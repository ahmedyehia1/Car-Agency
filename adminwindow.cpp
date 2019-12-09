#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <QtCore>
#include <QSqlTableModel>
#include <QtWidgets>
#include <QTableView>


AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

   // QSqlDatabase:: database();
    /*model = new QSqlTableModel(this,);
      model->setTable("table1");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setHeaderData(0, Qt::Horizontal, tr("Row1"));
      model->setHeaderData(1, Qt::Horizontal, tr("Row2"));
      ui->tableView->setModel(model);
      ui->tableView->show();

*/
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
