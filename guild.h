#ifndef GUILD_H
#define GUILD_H

#include <QDataStream>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QVector>

class Guild
{
public:
    Guild();
    Guild(QString, QString);

    QString name;
    QString zone;
    QString realm;
    QString faction;
    QString lastSeen;
    QStringList members;

    bool toBeUpdated;
};

QDataStream &operator<<(QDataStream &, const Guild &);
QDataStream &operator>>(QDataStream &, Guild &);

#endif // GUILD_H
