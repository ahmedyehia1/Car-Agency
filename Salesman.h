#ifndef SALESMAN_H
#define SALESMAN_H
#include <string>
#include <QString>
#include <QSqlQuery>
class Salesman
{
public:
    std::string name;
    int nmberOfSales;
    QSqlQuery qry;
    void addSalesman(QString Name)
    {
        qry.exec("INSERT INTO Salesman (Name) VALUES('"+Name+"')");
    }
    void removeSalesman(QString ID)
    {
        qry.exec("DELETE FROM Salesman WHERE ID_Salesman="+ID);
    }
    void editSalesman(QString Name,QString ID)
    {
        qry.exec("UPDATE Salesman SET Name='"+Name+"' WHERE ID_Salesman ="+ID);
    }
};
#endif
