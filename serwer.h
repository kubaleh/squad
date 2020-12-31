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
    QString message="no nic trzeba kończyć";
    explicit serwer(const QUrl &url, bool debug = false, QObject *parent = nullptr);
    Q_SIGNALS:
    void closed();
private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

signals:
    void showMessage(QString text);

public slots:
    void setMessage(QString text);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
    QString tekst;

};

#endif // SERWER_H
