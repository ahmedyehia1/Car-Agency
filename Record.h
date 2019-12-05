#ifndef RECORD_H
#define RECORD_H
#include <vector>
#include <string>
#include <Recipt.h>
class Record
{
public:
    std::vector <Recipt> sales;
    void showRecord();
    Recipt searchRecord(std::string selector , std::string value);
    void showMostSold();
};
#endif