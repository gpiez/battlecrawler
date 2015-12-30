#include "armoryplayer.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtDebug>

ArmoryPlayer::ArmoryPlayer()
{

}

void ArmoryPlayer::processAnswer(QString s) {
    QJsonObject doc = QJsonDocument::fromJson(s.toUtf8()).object();
    QJsonObject guild = doc["guild"].toObject();
    QString name = guild["name"].toString();
    QString realm = guild["realm"].toString();
    if (name.isEmpty() || realm.isEmpty()) return;
    qDebug() << name << '-' << realm;
    Guild g(name, realm);
    g.insert();
}

void ArmoryPlayer::processError(QString s) {
    qDebug() << s;
}
