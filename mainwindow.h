#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adminwindow.h"
#include <QMainWindow>
#include "customerwindow.h"
#include <QtSql>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase db;

    AdminWindow x;
    CustomerWindow y;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
