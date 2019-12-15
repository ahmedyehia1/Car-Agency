#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtCore>
#include <QtGui>
#include <QSqlDatabase>

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase DB;
    QSqlQueryModel *model_Vehicle = new QSqlQueryModel;
    QSqlQueryModel *model_OwnedVehicle = new QSqlQueryModel;
    explicit CustomerWindow(QWidget *parent = nullptr);

    ~CustomerWindow();
//    QSqlDatabase *ydb;
//    QSqlDatabase DB;
//    void DBconnect(QSqlDatabase dw)
//    {
//        ydb =&dw;
//    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CustomerWindow *ui;
    QSqlTableModel *model;
    QString Temp_ID_Customer;

};

#endif // CUSTOMERWINDOW_H
