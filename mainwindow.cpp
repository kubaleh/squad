#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serwer.h"
#include <QDebug>
bool to_change=true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->chat_text->document()->setDefaultStyleSheet("div{color:#4ab0d9;} div_2{color:#d90d32}");
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::setString(QString text){
    QStringList recieved = text.split( "*" );
    QString type = recieved.value( 1 );
    QString username_rec = recieved.value( 2 );
    QString val = recieved.value( 3 );
    if(type=="chat"){
        if(username_rec!=ui->username->displayText())
            ui->chat_text->insertHtml("<div>"+username_rec+": "+val+"</div><br>");
        else
            ui->chat_text->insertHtml("<div_2>YOU: "+val+"</div_2><br>");
    }
    else if(type=="file"){
        if(username_rec!=ui->username->displayText()){
            ui->textEdit->setText(val);
            to_change=false;
        }
    }
    else if(type=="join"){
        ui->chat_text->insertHtml("<div>"+username_rec+" now joined</div><br>");
    }
}
void MainWindow::on_username_returnPressed(){

    //ui->username->clear();
}
void MainWindow::on_chat_message_returnPressed(){
    QString chat_message=ui->chat_message->displayText(); // analogicznie

    qDebug() << chat_message;
    //send_message
    ui->chat_message->clear();
    emit sendMessageChat("chat",this->username,chat_message);
}

void MainWindow::on_refresh_clicked(){
    qDebug()<<"Refresh";
}
void MainWindow::on_username_editingFinished(){
    this->username=ui->username->displayText(); // tak można pobrać nazwę użytkownika
    qDebug() << this->username;
}

void MainWindow::on_textEdit_textChanged(){
    if(to_change){
        QString chat_message=ui->textEdit->toPlainText();
        emit sendMessageChat("file",this->username,chat_message);
    }
    to_change=true;
}
