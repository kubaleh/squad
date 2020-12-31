#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serwer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    //ui->textEdit->setText(client.message);
    //client.closed();
    //serwer client(QUrl(QStringLiteral("ws://kubaleh.herokuapp.com")), 1);
    //QObject::connect(&client, &serwer::closed, 0, &QCoreApplication::quit);
    //client.update(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setString(QString text)
{
    ui->textEdit->setText(text);
}
