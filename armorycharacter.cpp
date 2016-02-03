#include "armorycharacter.h"
#include "bossindex.h"
#include "mainwindow.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtDebug>
#include <QFile>

ArmoryCharacter::ArmoryCharacter()
{
    itemSlots << "head" << "neck" << "shoulder" << "back" << "chest"
              << "shirt" << "wrist" << "hands" << "waist" << "legs"
              << "feet" << "finger1" << "finger2" << "trinket1" << "trinket2"
              << "mainHand" << "offHand";
}

void ArmoryCharacter::insert(const Character& c)
{
    QString longName = c.name + "-" + c.realm;
    QHash<QString, int>::iterator it = characterLongNameIndex.find(longName);
    if (it == characterLongNameIndex.end()) {
//        toBeUpdated = true;
        int pi = characters.size();
        characters.append(c);
        characterLongNameIndex[longName] = pi;
        qDebug() << "Player " << longName << " added";

        characterNameIndex[c.name] = pi;

    } else {
        characters[characterLongNameIndex[longName]] = c;
        qDebug() << "Player " << longName << " updated";
    }
}

void ArmoryCharacter::save()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << characters;
    out << characterLongNameIndex;
    out << characterNameIndex;
}

void ArmoryCharacter::load()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()) {
        QDataStream in(&file);
        in >> characters;
        in >> characterLongNameIndex;
        in >> characterNameIndex;
    }
}

void ArmoryCharacter::updateCharacters() {
    if (requestsPending) return;

    int max = characters.size();
    for (int i=0; i<max; i++) {
        Character p = characters[i];
        ui->setProgress(i+1, max);
        if (i>100) break;
        QString req("https://eu.api.battle.net/wow/character/");
        req += p.realm;
        req += "/";
        req += p.name;
        req += "?fields=guild+achievements+items+progression&locale=de_DE&apikey=";
        req += ui->getApikey();
        request(QUrl(req));
    }
}

void ArmoryCharacter::processAnswer(QString s) {
    Character c;
    QJsonObject doc = QJsonDocument::fromJson(s.toUtf8()).object();
    c.name = doc["name"].toString();
    c.realm = doc["realm"].toString();
    QJsonObject guild = doc["guild"].toObject();
    QString name = guild["name"].toString();
    QString realm = guild["realm"].toString();
    if (!guild.isEmpty() && !realm.isEmpty()) {;
//        qDebug() << name << '-' << realm;
        Guild g(name, realm);
        ArmoryGuild::insert(g);
    }

    QJsonObject items = doc["items"].toObject();
    c.itemLevelMax = items["averageItemLevel"].toInt();
    int i=0;
    for (QString slot: itemSlots)
        c.itemLevels[i++] = items[slot].toObject()["itemLevel"].toInt();

    QJsonObject achievements = doc["achievements"].toObject();
    QJsonArray achievementsCompleted = achievements["achievementsCompleted"].toArray();
    QJsonArray achievementsCompletedTimestamp = achievements["achievementsCompletedTimestamp"].toArray();
    for (QJsonValue a: achievementsCompleted)
        c.achievements.append(a.toInt());
    for (QJsonValue t: achievementsCompletedTimestamp)
        c.achievementsTimestamp.append(t.toDouble());
    QJsonArray::iterator ita = achievementsCompleted.begin();
    QJsonArray::iterator itt = achievementsCompletedTimestamp.begin();
    for (int i=0; i<NFINGERPRINTS; i++) {
        while (ita != achievementsCompleted.end() && ita->toInt() <= FINGERPRINTS[i]) {
            int achievement = ita++->toInt();
            int timestamp = itt++->toInt();
            if (achievement == FINGERPRINTS[i]) {
                c.fingerprints[i] = timestamp;
                break;
            }

        }
    }

    const QJsonObject progression = doc["progression"].toObject();
    const QJsonArray raids = progression["raids"].toArray();
    for(QJsonValue raidVal: raids) {
        const QJsonObject raid = raidVal.toObject();
        for(const QJsonValue bossVal: raid["bosses"].toArray()) {
            const QJsonObject boss = bossVal.toObject();
            int bIndex = bossIndex[boss["name"].toString()];
            if (bIndex > BossIndex::nBoss)
                qDebug() << "boss index out of range" << bIndex;
            else
                c.boss[bIndex] = boss["timestamp"].toInt();
        }
    }
    ArmoryCharacter::insert(c);
}

void ArmoryCharacter::processError(QString s) {
    qDebug() << s;
}
