#include "censusdatabase.h"

#include <QDebug>

CensusDatabase::CensusDatabase(QString s) {
    int p = s.indexOf("[\"Servers\"] = {");
    db = parseServers(s, p);
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
    do {
        QString token = parseNext(s, p);
        if (token.left(2) == "[\"" || token.right(2) == "\"]") {
            key = token.mid(2, token.length()-4);
        } else if (token == "}") {
            break;
        } else if (token == "{") {
            servers[key] = parseServers(s, p);
        } else {
            if (key.isEmpty()) {
                servers[QString::number(index)] = token;
                index++;
            } else
                servers[key] = token;
        }
    } while(true);
    return servers;
}

Node CensusDatabase::parseFactions(QString s, int& p) {
    Node factions;
    return factions;
}
