#ifndef RECIPT_H
#define RECIPT_H
#include <string>
#include <Vehicle.h>
#include <Salesman.h>
#include <Customer.h>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
class Recipt
{
public:
    Vehicle vehicle;
    Salesman providedBy;
    std::string data;
    Customer customer;
    std::string paymentMethod;
    std::string paymentDetails;
    QSqlQuery qry;
    //Payment INFo (customization ,Sold,Maintenance)
    void addRecipt(QString ID_Vehicle,QString ID_Customer,QString ID_Salesman,QString PaymentMethod,QString PaymentInfo,QString Exchange_ID)
    {
        if(PaymentInfo=="Exchange")
        {
            qry.exec("INSERT INTO Record (ID_Vehicle,ID_Salesman,ID_Customer,PaymentMethod,PaymentInfo) VALUES("+ID_Vehicle+","+ID_Salesman+","+ID_Customer+",'"+PaymentMethod+"','"+PaymentInfo+"')");
            //qDebug()<<qry.lastQuery();
            //qry.exec("UPDATE Salesman SET NoOfSales=NoOfSales+1 WHERE ID_Salesman="+ID_Salesman);
            qry.exec("UPDATE Vehicle SET Status='"+PaymentInfo+"' WHERE ID_Vehicle ="+ID_Vehicle);
            qry.exec("UPDATE Vehicle SET Status='Sale' WHERE ID_Vehicle ="+Exchange_ID);
        }
        else
        {
            qry.exec("INSERT INTO Record (ID_Vehicle,ID_Salesman,ID_Customer,PaymentMethod,PaymentInfo) VALUES("+ID_Vehicle+","+ID_Salesman+","+ID_Customer+",'"+PaymentMethod+"','"+PaymentInfo+"')");
            //qDebug()<<qry.lastQuery();
            qry.exec("UPDATE Salesman SET NoOfSales=NoOfSales+1 WHERE ID_Salesman="+ID_Salesman);
            qry.exec("UPDATE Vehicle SET Status='"+PaymentInfo+"' WHERE ID_Vehicle ="+ID_Vehicle);
        }



    }
//    void editRecipt(QString ID_Sale,QString ID_Vehicle,QString ID_Customer,QString ID_Salesman,QString PaymentMethod,QString PaymentInfo)
//    {
//        qry.exec("");
//    }
};
#endif
