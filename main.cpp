#include "mainwindow.h"


#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Hatem/Desktop/sw_project/carAgency/carAgency.db");
    MainWindow w;
    w.show();

    return a.exec();
}
