#include "armory.h"

#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>

MainWindow* Armory::ui;

qint64 Armory::requestsPending;

QVector<Character> Armory::characters;
QHash<QString, int> Armory::characterNameIndex;
QHash<QString, int> Armory::characterLongNameIndex;
QVector<Guild> Armory::guilds;
QHash<QString, int> Armory::guildNameIndex;
QHash<QString, int> Armory::guildLongNameIndex;
QString Armory::apikey;

void Armory::request(QUrl url){
    requestsPending++;
//    qDebug() << "request: " << url.toString();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestReceived(QNetworkReply*)));
//    qDebug() << url.toString();
    QNetworkRequest request(url);
//    request.setRawHeader("Accept-Encoding", "gzip,deflate");
    QNetworkReply* reply = manager->get(request);
    QEventLoop loop;
    QTimer::singleShot(100, &loop, SLOT(quit()));
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

void Armory::init(MainWindow *ui, QString apikey)
{
    Armory::ui = ui,
    Armory::apikey = apikey;
}

bool Armory::getRequestsPending()
{
    return !!requestsPending;
}

void Armory::requestReceived(QNetworkReply *reply)
{
    reply->deleteLater();

    if(reply->error() == QNetworkReply::NoError) {
        // Get the http status code
        int v = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (v >= 200 && v < 300) // Success
        {
             // Here we got the final reply
            QString replyText = reply->readAll();
            processAnswer(replyText);
//            qDebug() << "reply: " << replyText;
            requestsPending--;
        }
        else if (v >= 300 && v < 400) // Redirection
        {
            // Get the redirection url
            QUrl newUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
            // Because the redirection url can be relative,
            // we have to use the previous one to resolve it
            newUrl = reply->url().resolved(newUrl);

            QNetworkAccessManager *manager = reply->manager();
            QNetworkRequest redirection(newUrl);
            QNetworkReply *newReply = manager->get(redirection);
            requestReceived(newReply);
            return; // to keep the manager for the next request
        }
    }
    else
    {
        // Error
        processError(reply->errorString());
//       qDebug() << "reply: " << reply->errorString();
        requestsPending--;
    }

    reply->manager()->deleteLater();
    if (!requestsPending)
        emit requestsDone();
}
