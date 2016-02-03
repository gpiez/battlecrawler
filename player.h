#ifndef PLAYER_H
#define PLAYER_H

#include <QHash>
#include <QString>
#include <QUrl>
#include <QVector>

static constexpr int NFINGERPRINTS = 3;
static constexpr int FINGERPRINTS[NFINGERPRINTS] = { 1111,2222,3333 };

class Player
{
public:
    Player();
    Player(QString name, QString realm);

    QUrl armoryLink();
    void insert();

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

    QVector<GuildHistory> guildHistory;

    static QVector<Player> players;
    static QHash<QString, int> playerNameIndex;
    static QHash<QString, int> playerLongNameIndex;

    static void save();
    static void load();
};

QDataStream &operator<<(QDataStream &, const Player &);
QDataStream &operator>>(QDataStream &, Player &);

#endif // PLAYER_H
