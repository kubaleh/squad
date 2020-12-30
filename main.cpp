#include "mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
#include "serwer.h"
#include <QtCore/QDebug>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QSplashScreen * splash=new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/Jakub Lehnhardt/Desktop/cat.png"));
    splash->show();
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    QTimer::singleShot(5000, splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));
    w.show();

    //komentarz

    serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    qDebug()<<"co toasdas: "<<client.message;
    QObject::connect(&client, &serwer::closed, &a, &QCoreApplication::quit);
    //qDebug()<<"co to: "<<client.message;

    return a.exec();
}
