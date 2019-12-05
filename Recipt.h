#ifndef RECIPT_H
#define RECIPT_H
#include <string>
#include <Vehicle.h>
#include <Salesman.h>
#include <Customer.h>
class Recipt
{
public:
    Vehicle vehicle;
    Salesman providedBy;
    std::string data;
    Customer customer;
    std::string paymentMethod;
    std::string paymentDetails;
};
#endif