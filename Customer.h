#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <Person.h>
#include <Vehicle.h>
#include <QString>
#include <QSqlQuery>

class Customer : public Person
{
public:
    std::string id;
    std::vector <Vehicle> ownedVehicle;
    float balance;
    void buy(Vehicle vehicle);
    void sell(Vehicle vehicle);
    void exchangeVehicle(Vehicle oldVehicle,Vehicle newVehicle);
    std::string checkStatus();
    QSqlQuery qry;

    void addCustomer(QString Name,QString UserName,QString Password,QString NationalID)
    {
        qry.exec("INSERT INTO Customer (Name,UserName,Password,National_ID) VALUES('"+Name+"','"+UserName+"','"+Password+"','"+NationalID+"')");
    }
    void editCustomer(QString CustomerID,QString Name,QString UserName,QString Password,QString NationalID)
    {
        qry.exec("UPDATE Customer SET Name = '"+Name+"',UserName = '"+UserName+"',Password = '"+Password+"',National_ID = '"+NationalID+"' WHERE ID_Customer="+CustomerID);
    }
};
#endif
