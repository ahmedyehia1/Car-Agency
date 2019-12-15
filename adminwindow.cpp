#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QItemSelectionModel>
#include <QtCore>
#include <QSqlTableModel>
#include <QtWidgets>
#include <QTableView>
#include <QLineEdit>
#include <Vehicle.h>
#include <QModelIndex>
#include <QDebug>
#include <QModelIndexList>
#include <Customer.h>
#include <Salesman.h>
#include <Recipt.h>
#include <QComboBox>

//#include


AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    QSqlDatabase  localdb =QSqlDatabase::database(); // connecting this window to database



        model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
        ui->tableView->setModel(model_Vehicle);


    model_Customer->setQuery("SELECT * FROM Customer");
     ui->tableView_2->setModel(model_Customer);

    model_Salesman->setQuery("SELECT * FROM Salesman");
    ui->tableView_3->setModel(model_Salesman);

    model_Recipt->setQuery("SELECT * FROM Record");
    ui->tableView_4->setModel(model_Recipt);

    model_C_M->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Status FROM Vehicle WHERE Status IN ('Customization','Maintenance')");
    ui->tableView_5->setModel(model_C_M);



}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_2_clicked()
{
    //add Vehicle
    Vehicle *temp= new Vehicle;
    temp->addVehicle(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text());
    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView->setModel(model_Vehicle);
}

void AdminWindow::on_pushButton_clicked()
{
    //edit Vehicle
    Vehicle *temp= new Vehicle;
     QItemSelectionModel *tempIndex = ui->tableView->selectionModel();
     QString ID=ui->tableView->model()->data(tempIndex->selectedIndexes().first()).toString();
     temp->editVehicle(ID,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text());
     model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
     ui->tableView->setModel(model_Vehicle);
}

void AdminWindow::on_pushButton_3_clicked()
{
    //Remove Vehicle
    //Vehicle *temp= new Vehicle;
    QItemSelectionModel *tempIndex = ui->tableView->selectionModel();

    //qDebug()<<tempIndex->selectedIndexes().first();
    Vehicle *temp= new Vehicle;
    temp->removeVehicle(ui->tableView->model()->data(tempIndex->selectedIndexes().first()).toString());
    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView->setModel(model_Vehicle);
}



void AdminWindow::on_pushButton_4_clicked()
{
    //add customer,line edit  from 6 to 9(name,username,password,national id)
    Customer temp;
    temp.addCustomer(ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->lineEdit_8->text(),ui->lineEdit_9->text());

    model_Customer->setQuery("SELECT * FROM Customer");
    ui->tableView_2->setModel(model_Customer);

}

void AdminWindow::on_pushButton_5_clicked()
{
    //edit Customer
    Customer temp;
    QItemSelectionModel *tempIndex = ui->tableView_2->selectionModel();
    QString ID=ui->tableView_2->model()->data(tempIndex->selectedIndexes().first()).toString();
    temp.editCustomer(ID,ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->lineEdit_8->text(),ui->lineEdit_9->text());

    model_Customer->setQuery("SELECT * FROM Customer");
    ui->tableView_2->setModel(model_Customer);
}

void AdminWindow::on_pushButton_10_clicked()
{
    //add salesman line edit(10)
    Salesman temp;
    temp.addSalesman(ui->lineEdit_10->text());
    model_Salesman->setQuery("SELECT * FROM Salesman");
    ui->tableView_3->setModel(model_Salesman);
}

void AdminWindow::on_pushButton_11_clicked()
{
    //edit Salesman
    Salesman temp;
    QItemSelectionModel *tempIndex = ui->tableView_3->selectionModel();
    QString ID=ui->tableView_3->model()->data(tempIndex->selectedIndexes().first()).toString();
    temp.editSalesman(ui->lineEdit_10->text(),ID);


    model_Salesman->setQuery("SELECT * FROM Salesman");
    ui->tableView_3->setModel(model_Salesman);
}

void AdminWindow::on_pushButton_12_clicked()
{
    //remove Salesman
    Salesman temp;
    QItemSelectionModel *tempIndex = ui->tableView_3->selectionModel();
    QString ID=ui->tableView_3->model()->data(tempIndex->selectedIndexes().first()).toString();
    temp.removeSalesman(ID);
    model_Salesman->setQuery("SELECT * FROM Salesman");
    ui->tableView_3->setModel(model_Salesman);
}

void AdminWindow::on_pushButton_14_clicked()
{
    //add Recipt lineEdit(11,12,13,14,17)
    Recipt temp;
    temp.addRecipt(ui->lineEdit_11->text(),ui->lineEdit_13->text(),ui->lineEdit_12->text(),ui->lineEdit_14->text(),ui->comboBox_2->currentText(),ui->lineEdit_17->text());
    model_Recipt->setQuery("SELECT * FROM Record");
    ui->tableView_4->setModel(model_Recipt);
    model_Salesman->setQuery("SELECT * FROM Salesman");
    ui->tableView_3->setModel(model_Salesman);
    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView->setModel(model_Vehicle);

    model_C_M->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Status FROM Vehicle WHERE Status IN ('Customization','Maintenance')");
    ui->tableView_5->setModel(model_C_M);
}

void AdminWindow::on_pushButton_9_clicked()
{
    //finish maintenance
    QItemSelectionModel *tempIndex = ui->tableView_5->selectionModel();
    QString ID=ui->tableView_5->model()->data(tempIndex->selectedIndexes().first()).toString();
    QSqlQuery qry;
    qry.exec("UPDATE Vehicle SET Status = 'Finished' WHERE ID_Vehicle ="+ID);
    model_C_M->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Status FROM Vehicle WHERE Status IN ('Customization','Maintenance')");
    ui->tableView_5->setModel(model_C_M);
}

void AdminWindow::on_pushButton_6_clicked()
{
    //search

    Vehicle temp;
    QString text;

    temp.Search(ui->comboBox->currentText(),ui->lineEdit_16->text(),&text);
    qDebug()<<text;
    model_Vehicle->setQuery(text);
    ui->tableView->setModel(model_Vehicle);

}

void AdminWindow::on_pushButton_7_clicked()
{
    //clear search
    model_Vehicle->setQuery("SELECT ID_Vehicle,Type,Model,Manfacture,Color,Price FROM Vehicle WHERE Status='Sale'");
    ui->tableView->setModel(model_Vehicle);
}
