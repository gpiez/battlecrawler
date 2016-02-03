#ifndef CHARACTER_H
#define CHARACTER_H

#include "bossindex.h"

#include <QHash>
#include <QString>
#include <QUrl>
#include <QVector>

static constexpr int NFINGERPRINTS = 6;
static constexpr int FINGERPRINTS[NFINGERPRINTS] = { 424, 430, 885, 1292, 3496, 4496 };

class Character
{
public:
    Character();
    Character(QString name, QString realm);

    QUrl armoryLink();

    int zone;
    bool toBeUpdated;

    int lastModified;
    QString name;
    QString realm;
    int klass;
    int race;
    int gender;
    int level;
    int achievementPoints;
    int faction;

    struct GuildHistory {
        QString guild;
        int joined;
        int left;
    };

    int itemLevels[17];
    int itemLevelMax;

    int fingerprints[NFINGERPRINTS];

    QVector<int> achievements;
    QVector<double> achievementsTimestamp;

    QVector<GuildHistory> guildHistory;
    int boss[bossIndex.nBoss+1];                      //timestamp of last bosskill

};

QDataStream &operator<<(QDataStream &, const Character &);
QDataStream &operator>>(QDataStream &, Character &);

#endif // PLAYER_H
