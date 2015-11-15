#ifndef GUILD_H
#define GUILD_H

#include <QDataStream>
#include <QString>
#include <QStringList>

class Guild
{
public:
    Guild();

    QString name;
    QString zone;
    QString server;
    QString faction;
    QString lastSeen;
    QStringList members;
};

QDataStream &operator<<(QDataStream &out, const Guild &painting);

#endif // GUILD_H
