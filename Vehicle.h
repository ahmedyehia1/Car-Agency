#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <vector>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
class Vehicle
{
public:
    QSqlQuery qry;
    std::string vehicleType;
    std::string manufacturer;
    std::string model;
    //std::vector <std::string> availableColors;
    //int index;
    std::string color;
    float engineCC;
    std::string status;
//    std::string plateNum;
    float zeroPrice;
//    float secondHandPrice;
//    int availableNum;
    float servesCost;
    //void addToMaintenance();
    //void addToCustomization();

    void addVehicle(QString Type,QString Manufacturer,QString Model,QString Color,QString Price)
    {
        qry.exec("INSERT INTO Vehicle (Type,Manfacture,Model,Color,Price) VALUES('"+Type+"','"+Manufacturer+"','"+Model+"','"+Color+"',"+Price+")");
    }
    void removeVehicle(QString ID)
    {
        qry.exec("DELETE FROM Vehicle WHERE ID_Vehicle="+ID);

    }
    void editVehicle(QString ID,QString Type,QString Manufacturer,QString Model,QString Color,QString Price)
    {
        qry.exec("UPDATE Vehicle SET Type ='"+Type+"' ,Manfacture = '"+Manufacturer+"',Model = '"+Model+"',Color = '"+Color+"',Price = '"+Price+"' WHERE ID_Vehicle="+ID);
    }
    void Search(QString searchMethod,QString searchParamter,QString *text)
    {
        if(searchMethod == "Price")
        {
            *text="SELECT ID_Vehicle,Type,Manfacture,Model,Color,Price FROM Vehicle WHERE "+searchMethod+"="+searchParamter+" AND Status ='Sale'";
        }
        else
        {
            *text="SELECT ID_Vehicle,Type,Manfacture,Model,Color,Price FROM Vehicle WHERE "+searchMethod+"='"+searchParamter+"' AND Status ='Sale'";
        }
    }
};

#endif
