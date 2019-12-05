#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <vector>
class Vehicle
{
public:
    std::string vehicleType;
    std::string manufacturer;
    std::string model;
    std::vector <std::string> availableColors;
    int index;
    std::string color;
    float engineCC;
    std::string status;
    std::string plateNum;
    float zeroPrice;
    float secondHandPrice;
    int availableNum;
    float servesCost;
    void addToMaintenance();
    void addToCustomization();
};
#endif