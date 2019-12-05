#ifndef AGENCY_H
#define AGENCY_H
#include <vector>
#include <Vehicle.h>
#include <Salesman.h>
class Agency
{
public:
    std::vector <std::vector <Vehicle>> vehicles;
    std::vector <std::vector <Vehicle>> soldVehicles;
    float finaces;
    std::vector <Salesman> salesman;
};
#endif