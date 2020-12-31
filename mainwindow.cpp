#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serwer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::setString(QString text){
    ui->textEdit->setText(text);
}
