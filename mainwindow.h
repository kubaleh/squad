#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serwer.h"
#include <QtCore/QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    void setString(QString text);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
