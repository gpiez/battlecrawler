#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <QtDebug>

#include "armoryguild.h"
#include "mainwindow.h"

ArmoryGuild::ArmoryGuild()
{

}

void ArmoryGuild::insert(const Guild& g)
{
    QString longName = g.name + "-" + g.realm;
    QHash<QString, int>::iterator it = guildLongNameIndex.find(longName);
    if (it == guildLongNameIndex.end()) {
//        toBeUpdated = true;
        int pi = guilds.size();
        guilds.append(g);
        guildLongNameIndex[longName] = pi;
        qDebug() << "Guild  " << longName << " added";
        guildNameIndex[g.name] = pi;

    } else {
        guilds[*it] = g;
        guilds[*it].toBeUpdated = true;
    }
}

void ArmoryGuild::save()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << guilds;
//   out << guildLongNameIndex;
//    out << guildNameIndex;
}

void ArmoryGuild::load()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()) {
        QDataStream in(&file);
        in >> guilds;
//        in >> guildLongNameIndex;
//        in >> guildNameIndex;
    }
    //TODO: rebuild indices
}

void ArmoryGuild::updateGuilds() {
    if (requestsPending) return;

    for (Guild g: guilds) {
        if (g.name == "noguild") continue;
        QString req("https://eu.api.battle.net/wow/guild/");
        req += g.realm;
        req += "/";
        req += g.name;
        req += "?fields=members&locale=de_DE&apikey=";
        req += ui->getApikey();
        request(QUrl(req));
    }
}

void ArmoryGuild::processAnswer(QString s) {
//    qDebug() << s;
    QJsonObject doc = QJsonDocument::fromJson(s.toUtf8()).object();
//    int lastModified = doc["lastModified"].toInt();
    QString guild = doc["name"].toString();
    QJsonArray members = doc["members"].toArray();
    for (QJsonValue c: members) {
        QString name = c.toObject()["character"].toObject()["name"].toString();
        QString realm = c.toObject()["character"].toObject()["realm"].toString();
        qDebug() << name << '-' << realm;
        Character p(name, realm);
        ArmoryCharacter::insert(p);
        ui->addPlayerToTree(realm, guild, name);
    }
}

void ArmoryGuild::processError(QString s) {
    qDebug() << s;
}

