#include "player.h"

#include <QDataStream>
#include <QFile>
#include <QtDebug>

QVector<Character> Character::players;
QHash<QString, int> Character::playerNameIndex;
QHash<QString, int> Character::playerLongNameIndex;

Character::Character()
{

}

Character::Character(QString name, QString server)
{
    this->name = name;
    this->realm = server;
}

void Character::insert()
{
    QString longName = this->name + "-" + this->realm;
    QHash<QString, int>::iterator it = playerLongNameIndex.find(longName);
    if (it == playerLongNameIndex.end()) {
        toBeUpdated = true;
        int pi = players.size();
        players.append(*this);
        playerLongNameIndex[longName] = pi;
        qDebug() << "Player " << longName << " added";

        playerNameIndex[name] = pi;

    } else {
        players[*it].toBeUpdated = true;
    }
}

void Character::save()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << players;
    out << playerLongNameIndex;
    out << playerNameIndex;
}

void Character::load()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()) {
        QDataStream in(&file);
        in >> players;
        in >> playerLongNameIndex;
        in >> playerNameIndex;
    }
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
