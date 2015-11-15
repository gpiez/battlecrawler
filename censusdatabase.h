#ifndef CENSUSDATABASE_H
#define CENSUSDATABASE_H

#include "armoryguild.h"
#include "guild.h"
#include "player.h"

#include <QMap>
#include <QString>
#include <QVariant>

typedef QMap<QString, QVariant> Node;

class CensusDatabase
{
public:
    CensusDatabase(QString s);
    bool nextPlayer(QString&);
    int nPlayers();

    void createGuilds();
    int nGuilds();
    void updateGuilds();
    void saveGuilds();
private:
    ArmoryGuild ag;
    Node parse(QString s);
    Node parseServers(QString s, int &p);

    Player currentPlayer;
    int level;
    QList<Player> players;
    QMap<QString,Guild> guilds;
    QString apikey;
};

#endif // CENSUSDATABASE_H
