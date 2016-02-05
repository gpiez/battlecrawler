#ifndef PLAYER_H
#define PLAYER_H

#include <QHash>
#include <QString>
#include <QVector>
#include "character.h"

class Player
{
public:
    Player();
    Player(QString id);

    QString id;
    QVector<QString> characterIDs;

    int fingerprints[NFINGERPRINTS];
};

QDataStream &operator<<(QDataStream &, const Player &);
QDataStream &operator>>(QDataStream &, Player &);

#endif // PLAYER_H
