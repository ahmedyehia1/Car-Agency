#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    disconnect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    qDebug()<<username<<" "<<password;

}
