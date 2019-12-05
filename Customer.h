#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <Person.h>
#include <Vehicle.h>
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
};
#endif