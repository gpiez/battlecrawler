#ifndef CENSUSDATABASE_H
#define CENSUSDATABASE_H

#include "armoryguild.h"
#include "armoryplayer.h"
#include "guild.h"
#include "player.h"

#include <QMap>
#include <QString>
#include <QVariant>

typedef QMap<QString, QVariant> Node;

class MainWindow;

class CensusDatabase
{
public:
    CensusDatabase(MainWindow*);
    void update(QString);
    bool nextPlayer(QString&);
    int nPlayers();

    void createGuilds();
    int nGuilds();
    void updateGuilds();
    void saveGuilds();
    void updatePlayers();
private:
    ArmoryGuild ag;
    ArmoryPlayer ap;
    Node parse(QString s);
    Node parseServers(QString s, int &p);

    Player currentPlayer;
    int level;
    QHash<QString, int> guildNameIndex;
    QHash<QString, int> guildLongNameIndex;
    QString apikey;
    MainWindow* ui;
};

#endif // CENSUSDATABASE_H
