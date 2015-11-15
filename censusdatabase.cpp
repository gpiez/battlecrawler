#include "armoryguild.h"
#include "censusdatabase.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QSettings>

CensusDatabase::CensusDatabase(QString fileName):
    level(0)
{
    QSettings settings("piesoft","battlecrawler");
    apikey=settings.value("apikey").toString();

    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    int p = s.indexOf("[\"Servers\"] = {");
    parseServers(s, p);
}

int CensusDatabase::nPlayers()
{
    return players.size();
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
                currentPlayer.server = key.mid(key.indexOf('-')+1);
                break;
            case 3:
                currentPlayer.faction = key;
                break;
            case 4:
                currentPlayer.race = key;
                break;
            case 5:
                currentPlayer.klass = key;
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
                currentPlayer.guild = node["1"].toString();
                currentPlayer.guild.remove('"');
// ?? seen on server ??  currentPlayer.server = node["2"];
                currentPlayer.lastSeen = node["3"].toString();
                players.append(currentPlayer);
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

void CensusDatabase::createGuilds() {
    for(const Player p: players) {
        QString g = p.guild;
        if (g.isEmpty()) {
            g = "noguild";
        }
        QString key = g + "-" + p.server;
        guilds[key].name = g;
        guilds[key].faction = p.faction;
        guilds[key].server = p.server;
        guilds[key].members.append(p.name);
    }
}

void CensusDatabase::updateGuilds() {
    for (Guild g: guilds) {
        QString req("https://eu.api.battle.net/wow/guild/");
        req += g.server;
        req += "/";
        req += g.name;
        req += "?fields=members&locale=de_DE&apikey=";
        req += apikey;
        ag.request(QUrl(req));
    }
}

void CensusDatabase::saveGuilds()
{
    QFile file("battlecrawler.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << guilds;
}

int CensusDatabase::nGuilds()
{
    return guilds.size();
}
