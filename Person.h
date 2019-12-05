#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <Vehicle.h>
class Person
{
public:
    std::string name;
    std::string password;
    Vehicle searchVehicle(std::vector <Vehicle> vehicles,std::string method,std::string data);
    void setName(std::string name);
    void setPassword(std::string password);
};
#endif