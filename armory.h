#ifndef ARMORY_H
#define ARMORY_H

#include "guild.h"
#include "character.h"
#include "player.h"

#include <QUrl>

class MainWindow;
class QNetworkReply;

class Armory: public QObject
{
    Q_OBJECT
public:
    void request(QUrl);
    static void init(MainWindow* ui, QString apikey);
    static bool getRequestsPending();
    static QVector<Character> characters;
    static QHash<QString, int> characterNameIndex;
    static QHash<QString, int> characterLongNameIndex;
    static QVector<Guild> guilds;
    static QHash<QString, int> guildNameIndex;
    static QHash<QString, int> guildLongNameIndex;
    static QString apikey;
    static QVector<Player> players;
    static QHash<QString, int> playerNameIndex;
    static QHash<QString, int> playerLongNameIndex;

signals:
    void requestsDone();

protected:
    static qint64 requestsPending;
//    static qint64 currentRequest;

//    static QDateTime quota1Time;
//    static qint64 quota1request;
//    static QDateTime quota2Time;
//    static qint64 quota2request;

    static MainWindow* ui;

    virtual void processAnswer(QString) = 0;
    virtual void processError(QString) = 0;

public slots:
    void requestReceived(QNetworkReply *reply);
};

#endif // ARMORY_H
