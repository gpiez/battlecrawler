#include "achievementindex.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

void AchievementIndex::init()
{
    request(QUrl(QString("https://eu.api.battle.net/wow/data/character/achievements?locale=de_DE&apikey=") + apikey));
}

void AchievementIndex::processAnswer(QString answer)
{
    QJsonObject doc = QJsonDocument::fromJson(answer.toUtf8()).object();
    QJsonArray achievements = doc["achievements"].toArray();
    for (QJsonValue v: achievements) {
        QJsonObject category = v.toObject();
        for (QJsonValue a: category["achievements"].toArray()) {
            QJsonObject ao = a.toObject();
//            qDebug() << a.toObject()["id"].toInt() << a.toObject()["title"].toString();
            achievementIndex.insert(ao["id"].toInt(), ao["title"].toString() + "|" + ao["description"].toString());
        }

    }

}

void AchievementIndex::processError(QString)
{

}
