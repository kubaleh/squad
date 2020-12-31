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
    connect(&m_webSocket, &QWebSocket::disconnected, this, &serwer::closed);
    //connect(this, &serwer::showMessage, this,&serwer::setMessage);
    m_webSocket.open(QUrl(url));
}
void serwer::onConnected(){
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &serwer::onTextMessageReceived);
    //m_webSocket.sendTextMessage(QStringLiteral("Joined"));
}
void serwer::onTextMessageReceived(QString message){
    if (m_debug){
            qDebug() << "Message received:" << message;
    }
    this->setMessage(message);
    //m_webSocket.close();
}
void serwer::setMessage(QString text){
    this->message=text;
    qDebug() << "I am setting message "<<message;
    emit showMessage(text);
}
