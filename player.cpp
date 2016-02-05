#include "player.h"

#include <QDataStream>
#include <QFile>
#include <QtDebug>

Player::Player()
{

}

Player::Player(QString id):
    id(id)
{
}

QDataStream &operator<<(QDataStream &out, const Player &p)
{
    out <<
           p.id <<
           p.characterIDs;
    return out;
}

QDataStream &operator>>(QDataStream &in, Player &g)
{
    in >>
           g.characterIDs >>
           g.id;
    return in;
}
