#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serwer.h"
#include <QDebug>
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

void MainWindow::on_username_editingFinished(){
    QString username_text=ui->username->displayText(); // tak można pobrać nazwę użytkownika
    qDebug() << username_text;
}

void MainWindow::on_chat_message_returnPressed(){
    QString chat_message=ui->chat_message->displayText(); // analogicznie
    qDebug() << chat_message;
    //send_message
    ui->chat_message->setText("");
}
