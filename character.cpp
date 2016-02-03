#include "character.h"

#include <QDataStream>

Character::Character()
{

}

Character::Character(QString name, QString server)
{
    this->name = name;
    this->realm = server;
}

QDataStream &operator<<(QDataStream &out, const Character &g)
{
    out <<
           g.name <<
           g.zone <<
           g.realm <<
           g.faction <<
           g.lastModified;
    return out;
}

QDataStream &operator>>(QDataStream &in, Character &g)
{
    in >>
           g.name >>
           g.zone >>
           g.realm >>
           g.faction >>
           g.lastModified;
    return in;
}

