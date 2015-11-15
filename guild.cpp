#include "guild.h"

Guild::Guild()
{

}


QDataStream &operator<<(QDataStream &out, const Guild &g)
{
    out <<
           g.name <<
           g.zone <<
           g.server <<
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
           g.server >>
           g.faction >>
           g.lastSeen >>
           g.members;
    return in;
}
