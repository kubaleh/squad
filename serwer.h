#ifndef SERWER_H
#define SERWER_H


#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include "mainwindow.h"
#include <QTextEdit>
class serwer : public QObject
{
    Q_OBJECT
public:
    //void update(Ui::MainWindow *);
    explicit serwer(const QUrl &url, bool debug = false, QObject *parent = nullptr);
    Q_SIGNALS:
    void closed();
private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
    QString tekst;
};

#endif // SERWER_H
