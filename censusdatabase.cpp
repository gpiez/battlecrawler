#include "armoryguild.h"
#include "censusdatabase.h"
#include "mainwindow.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QSettings>

void CensusDatabase::update(QString fileName)
{
    level = 0;
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    int p = s.indexOf("[\"Servers\"] = {");
    parseServers(s, p);
}

CensusDatabase::CensusDatabase(MainWindow* ui, ArmoryGuild* ag, ArmoryCharacter* ap):
    ui(ui),
    ag(ag),
    ap(ap)
{
    QSettings settings("piesoft","battlecrawler");
    apikey=settings.value("apikey").toString();
    Armory::setui(ui);
}

int CensusDatabase::nPlayers()
{
    return Armory::characters.size();
}

QString parseNext(QString s, int& start) {
    while (s.mid(start,2) == "--" || s[start] == ' ' || s[start] == '=' || s[start] == ',' || s[start] == '\n' || s[start] == '\t' || s[start] == '\r')
        if (s.mid(start,2) == "--")
            while(s[start] != '\n')
                start++;
        else
            start++;

    bool inString = ( s[start] == '"');
    int tokenstart = start++;
    while(true) {
        QChar c = s[start];
        if (inString) {
            start++;
            if (c == '"') {
                inString = false;
            }
        } else {
            if (c == '"') {
                inString = true;
                start++;
            } else if (c != ' ' && c != '=' && c != '\n' && c != '\t'
                    && c != '\r' && c != ',' && c!= '{' && c != '}')
                start++;
            else
                break;
        }
    }
    return (s.mid(tokenstart, start-tokenstart));
}

Node CensusDatabase::parseServers(QString s, int& p) {
    Node servers;
    QString key;
    int index = 0;
    level++;
    do {
        QString token = parseNext(s, p);
        if (token.left(2) == "[\"" || token.right(2) == "\"]") {
            key = token.mid(2, token.length()-4);
            switch (level) {
            case 2:
                currentPlayer.realm = key.mid(key.indexOf('-')+1);
                break;
            case 3:
//                currentPlayer.faction = key.toInt();
                break;
            case 4:
//                currentPlayer.race = key.toInt();
                break;
            case 5:
//                currentPlayer.klass = key.toInt();
                break;
            case 6:
                currentPlayer.name = key;
                break;
            }
        } else if (token == "}") {
            break;
        } else if (token == "{") {
            if (level == 6) {
                Node node = parseServers(s, p);
                currentPlayer.level = node["0"].toInt();
// ?? seen on server ??  currentPlayer.server = node["2"];
                currentPlayer.toBeUpdated = true;
                ArmoryCharacter::insert(currentPlayer);
            } else
                parseServers(s, p);
        } else {
            if (key.isEmpty()) {
                servers[QString::number(index)] = token;
                index++;
            } else
                servers[key] = token;
        }
    } while(true);
    --level;
    return servers;
}

void CensusDatabase::updateGuilds() {
    if (ag->getRequestsPending()) return;

    for (Guild g: Armory::guilds) {
        if (g.name == "noguild") continue;
        QString req("https://eu.api.battle.net/wow/guild/");
        req += g.realm;
        req += "/";
        req += g.name;
        req += "?fields=members&locale=de_DE&apikey=";
        req += apikey;
        ag->request(QUrl(req));
    }
}

void CensusDatabase::updatePlayers() {
    if (ap->getRequestsPending()) return;

    int max = Armory::characters.size();
    for (int i=0; i<max; i++) {
        Character p = Armory::characters[i];
        ui->setProgress(i, max);
        if (i>100) break;
        QString req("https://eu.api.battle.net/wow/character/");
        req += p.realm;
        req += "/";
        req += p.name;
        req += "?fields=guild+achievements+items+progression&locale=de_DE&apikey=";
        req += apikey;
        ap->request(QUrl(req));
    }
}


int CensusDatabase::nGuilds()
{
    return Armory::guilds.size();
}
