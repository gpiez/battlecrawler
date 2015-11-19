#include "guild.h"

#include <QFile>
#include <QtDebug>

QVector<Guild> Guild::guilds;
QHash<QString, int> Guild::guildNameIndex;
QHash<QString, int> Guild::guildLongNameIndex;

Guild::Guild()
{

}

Guild::Guild(QString name, QString server)
{
    this->name = name;
    this->realm = server;
}

void Guild::insert()
{
    QString longName = this->name + "-" + this->realm;
    QHash<QString, int>::iterator it = guildLongNameIndex.find(longName);
    if (it == guildLongNameIndex.end()) {
        toBeUpdated = true;
        int pi = guilds.size();
        guilds.append(*this);
        guildLongNameIndex[longName] = pi;
        qDebug() << "Guild  " << longName << " added";
        guildNameIndex[name] = pi;

    } else {
        guilds[*it].toBeUpdated = true;
    }
}

void Guild::save()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << guilds;
    out << guildLongNameIndex;
    out << guildNameIndex;
}

void Guild::load()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()) {
        QDataStream in(&file);
        in >> guilds;
        in >> guildLongNameIndex;
        in >> guildNameIndex;
    }
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
