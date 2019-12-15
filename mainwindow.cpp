#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"

#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //disconnect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    db =QSqlDatabase::database();

    if(db.open())
    {
        ui->label_4->setText("connected");
    }
    else
    {
        ui->label_4->setText("not connected");
    }


}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    //qDebug()<<username<<" "<<password;

QSqlQuery qry(db);
    if(ui->radioButton->isChecked())
    {
        if(qry.exec("select Password from Admin where UserName='"+ username +"'"))
        {

            qry.next();
            if(qry.isValid())
            {
                if(password == qry.value(0).toString())
                {
                    x=new AdminWindow(this);
                    x->show();
                    this->hide();
                }
                else
                {
                    ui->label_4->setText("wrong password");
                }
            }
            else
            {
                ui->label_4->setText("username not found");
            }
        }



    }
    else if(ui->radioButton_2->isChecked())
    {
        if(qry.exec("select Password from Customer where UserName='"+ username +"'"))
        {

            qry.next();
            if(qry.isValid())
            {
                if(password == qry.value(0).toString())
                {
                    qry.exec("select ID_Customer FROM Customer WHERE UserName='"+username+"'");
                    qry.next();
                    qry.exec("UPDATE Agency SET ID_Customer ="+qry.value(0).toString());
                    y = new CustomerWindow(this);
                    y->show();
//                    y.DBconnect(db);
                    this->hide();
                }
                else
                {
                    ui->label_4->setText("wrong password");
                }
            }
            else
            {
                ui->label_4->setText("username not found");
            }
        }
    }
    //this->hide();




}
