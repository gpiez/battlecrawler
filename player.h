#ifndef PLAYER_H
#define PLAYER_H

#include <QHash>
#include <QString>
#include <QUrl>
#include <QVector>

class Player
{
public:
    Player();
    Player(QString name, QString realm);

    QUrl armoryLink();
    void insert();

    QString name;
    QString zone;
    QString realm;
    QString guild;
    QString race;
    QString klass;
    QString faction;
    QString lastSeen;
    int level;
    bool toBeUpdated;

    static QVector<Player> players;
    static QHash<QString, int> playerNameIndex;
    static QHash<QString, int> playerLongNameIndex;

    static void save();
    static void load();
};

QDataStream &operator<<(QDataStream &, const Player &);
QDataStream &operator>>(QDataStream &, Player &);

#endif // PLAYER_H
