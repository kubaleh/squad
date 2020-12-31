#include "serwer.h"
#include "mainwindow.h"
#include <QtCore/QDebug>
#include "ui_mainwindow.h"
QT_USE_NAMESPACE

serwer::serwer(const QUrl &url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &serwer::onConnected);
     qDebug() << "WebSocket server:1" << url;
    connect(&m_webSocket, &QWebSocket::disconnected, this, &serwer::closed);
    //connect(this, &serwer::showMessage, this,&serwer::setMessage);
    m_webSocket.open(QUrl(url));

     qDebug() << "WebSocket server:wrerew" << url;
}
void serwer::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &serwer::onTextMessageReceived);
    qDebug() << "WebSocket server:255";
    m_webSocket.sendTextMessage(QStringLiteral("Witaj"));
    qDebug() << "WebSocket server:256";
}
//! [onConnected]
//! [onTextMessageReceived]
void serwer::onTextMessageReceived(QString message)
{
    if (m_debug)
    {
            qDebug() << "WebSocket server:257";
            qDebug() << "Message received:" << message;
            this->setMessage(message);
            //this->message=message;
            //emit showMessage(message);
    }


    //tekst=message;
    //ui->textEdit->setText(message);
    //m_webSocket.close();
}

void serwer::setMessage(QString text)
{
    qDebug() << "WebSocket server:258";
    this->message=text;
    emit showMessage(text);
}
