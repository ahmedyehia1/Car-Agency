#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtCore>
#include <QtGui>
#include <QSqlTableModel>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    QSqlQueryModel *model_Vehicle = new QSqlQueryModel;
    QSqlQueryModel *model_Customer = new QSqlQueryModel;
    QSqlQueryModel *model_Salesman = new QSqlQueryModel;
    QSqlQueryModel *model_Recipt = new QSqlQueryModel;
    QSqlQueryModel *model_C_M = new QSqlQueryModel;
    QItemSelectionModel tempIndex;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::AdminWindow *ui;

    QSqlDatabase db;

};

#endif // ADMINWINDOW_H
