#include "customerwindow.h"
#include "mainwindow.h"
#include "ui_customerwindow.h"
#include <QSqlDatabase>
#include <QString>
#include <QTableView>
#include <QLineEdit>
#include <Vehicle.h>
#include <QComboBox>


CustomerWindow::CustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);

    QSqlDatabase  localdb =QSqlDatabase::database();

    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView_2->setModel(model_Vehicle);
    QSqlQuery qry(DB);
    qry.exec("SELECT ID_Customer FROM Agency");
    qry.next();
    Temp_ID_Customer = qry.value(0).toString();
    qDebug()<<Temp_ID_Customer;
    model_OwnedVehicle->setQuery("SELECT v.ID_Vehicle,Type,Model,Manfacture,Color,Status FROM Vehicle v INNER JOIN Record r ON v.ID_Vehicle = r.ID_Vehicle AND r.ID_Customer="+Temp_ID_Customer);
    ui->tableView->setModel(model_OwnedVehicle);


}

CustomerWindow::~CustomerWindow()
{
    delete ui;
}

void CustomerWindow::on_pushButton_clicked()
{
    //search Vehicle
    Vehicle temp;
    QString text;

    temp.Search(ui->comboBox->currentText(),ui->lineEdit->text(),&text);
    model_Vehicle->setQuery(text);
    ui->tableView_2->setModel(model_Vehicle);


}

void CustomerWindow::on_pushButton_2_clicked()
{
    //Clear search
    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView_2->setModel(model_Vehicle);

}
