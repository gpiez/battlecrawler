#ifndef CENSUSDATABASE_H
#define CENSUSDATABASE_H

#include <QMap>
#include <QString>
#include <QVariant>

typedef QMap<QString, QVariant> Node;

class CensusDatabase
{
public:
    CensusDatabase(QString s);
private:
    Node parse(QString s);
    Node parseServers(QString s, int &p);

    Node db;
    Node parseFactions(QString s, int &p);
};

#endif // CENSUSDATABASE_H
