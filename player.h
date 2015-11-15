#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QUrl>



class Player
{
public:
    Player();
    QUrl armoryLink();

    QString name;
    QString zone;
    QString server;
    QString guild;
    QString race;
    QString klass;
    QString faction;
    QString lastSeen;
    int level;

};

#endif // PLAYER_H
