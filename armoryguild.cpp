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
        Player p(name, realm);
        p.insert();
        ui->addPlayerToTree(realm, guild, name);
    }
}

void ArmoryGuild::processError(QString s) {
    qDebug() << s;
}

