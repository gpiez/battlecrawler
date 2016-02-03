#include "guild.h"

#include <QFile>

Guild::Guild()
{

}

Guild::Guild(QString name, QString server)
{
    this->name = name;
    this->realm = server;
}

QDataStream &operator<<(QDataStream &out, const Guild &g)
{
    out <<
           g.name <<
           g.zone <<
           g.realm <<
           g.faction <<
           g.lastSeen <<
           g.members;
    return out;
}

QDataStream &operator>>(QDataStream &in, Guild &g)
{
    in >>
           g.name >>
           g.zone >>
           g.realm >>
           g.faction >>
           g.lastSeen >>
           g.members;
    return in;
}
