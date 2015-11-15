#include "armory.h"

Armory::Armory()
{

}

void Armory::request(QUrl url){
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestReceived(QNetworkReply*)));
    qDebug() << url.toString();
    QNetworkReply* reply = manager->get(QNetworkRequest(url));
}

void Armory::requestReceived(QNetworkReply *reply)
{
    qDebug() << "reply";
    reply->deleteLater();

    if(reply->error() == QNetworkReply::NoError) {
        // Get the http status code
        int v = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (v >= 200 && v < 300) // Success
        {
             // Here we got the final reply
            QString replyText = reply->readAll();
            processAnswer(replyText);
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
    }

    reply->manager()->deleteLater();
}
