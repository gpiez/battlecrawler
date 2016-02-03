#ifndef CENSUSDATABASE_H
#define CENSUSDATABASE_H

#include "armoryguild.h"
#include "armorycharacter.h"
#include "guild.h"
#include "character.h"

#include <QMap>
#include <QString>
#include <QVariant>

typedef QMap<QString, QVariant> Node;

class MainWindow;

class CensusDatabase
{
public:
    CensusDatabase(MainWindow*, ArmoryGuild* ag, ArmoryCharacter* ap);
    void update(QString);
    bool nextPlayer(QString&);
    int nPlayers();

    void createGuilds();
    int nGuilds();
    void updateGuilds();
    void saveGuilds();
    void updatePlayers();
private:
    MainWindow* ui;
    ArmoryGuild* ag;
    ArmoryCharacter* ap;
    Node parse(QString s);
    Node parseServers(QString s, int &p);

    Character currentPlayer;
    int level;
    QHash<QString, int> guildNameIndex;
    QHash<QString, int> guildLongNameIndex;
};

#endif // CENSUSDATABASE_H
