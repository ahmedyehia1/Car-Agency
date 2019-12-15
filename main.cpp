#include "mainwindow.h"


#include <QApplication>
#include <QSqlDatabase>
#include <QDir>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
   // QDir dir ;
    //qDebug() <<dir.currentPath() ;


    //we need to find a solution for datapath
    db.setDatabaseName("./carAgency.db");
    MainWindow w;
    w.show();

    return a.exec();
}
