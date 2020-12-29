#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serwer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("123456789");
    //serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    //QObject::connect(&client, &serwer::closed, 0, &QCoreApplication::quit);
    //client.update(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

