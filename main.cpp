#include "mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
#include "serwer.h"
#include <QtCore/QDebug>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/logo.ico"));
    QSplashScreen * splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/logo.png"));
    splash->show();
    MainWindow w;
    w.setWindowTitle("</>Squad");
    w.setWindowState(Qt::WindowMaximized);
    QTimer::singleShot(5000, splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));
    w.show();
    serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    w.setString(client.message);
    QObject::connect(&client, &serwer::showMessage, &w, &MainWindow::setString);
    QObject::connect(&w, &MainWindow::sendMessageChat, &client, &serwer::send);
    //client.send("chat", "Jakub Lehnhardt", "Co tam mordo?");
    return a.exec();
}
