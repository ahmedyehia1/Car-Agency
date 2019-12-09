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

private:
    Ui::AdminWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;

};

#endif // ADMINWINDOW_H
