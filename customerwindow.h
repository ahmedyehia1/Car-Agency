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
    explicit CustomerWindow(QWidget *parent = nullptr);

    ~CustomerWindow();
//    QSqlDatabase *ydb;
//    QSqlDatabase DB;
//    void DBconnect(QSqlDatabase dw)
//    {
//        ydb =&dw;
//    }


private:
    Ui::CustomerWindow *ui;
    QSqlTableModel *model;

};

#endif // CUSTOMERWINDOW_H
