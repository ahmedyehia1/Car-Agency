#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <Person.h>
#include <Vehicle.h>
#include <Customer.h>
#include <Salesman.h>
class Admin : public Person
{
public:
    void editVehicle(Vehicle vehicle,std::string operation,std::string data);
    void editCustomer(Customer customer,std::string operation,std::string data);
    void editSalesman(Salesman salesman,std::string operation,std::string data);
};
#endif