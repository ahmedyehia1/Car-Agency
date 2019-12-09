#include "customerwindow.h"
#include "mainwindow.h"
#include "ui_customerwindow.h"
#include <QSqlDatabase>
#include <QString>


CustomerWindow::CustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);

    QSqlDatabase  localdb =QSqlDatabase::database();
    QString name = localdb.connectionName();
    // this method failed because we need an object of main window
    ui->label->setText(name);
    if(localdb.open())
    {
        ui->label->setText("connected");
    }


}

CustomerWindow::~CustomerWindow()
{
    delete ui;
}
