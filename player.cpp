#include "player.h"

#include <QDataStream>
#include <QFile>
#include <QtDebug>

QVector<Player> Player::players;
QHash<QString, int> Player::playerNameIndex;
QHash<QString, int> Player::playerLongNameIndex;

Player::Player()
{

}

Player::Player(QString name, QString server)
{
    this->name = name;
    this->realm = server;
}

void Player::insert()
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

void Player::save()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << players;
    out << playerLongNameIndex;
    out << playerNameIndex;
}

void Player::load()
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

QDataStream &operator<<(QDataStream &out, const Player &g)
{
    out <<
           g.name <<
           g.zone <<
           g.realm <<
           g.faction <<
           g.lastSeen;
    return out;
}

QDataStream &operator>>(QDataStream &in, Player &g)
{
    in >>
           g.name >>
           g.zone >>
           g.realm >>
           g.faction >>
           g.lastSeen;
    return in;
}
