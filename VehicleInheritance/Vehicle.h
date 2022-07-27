#pragma once
#include <string>

using namespace std;

class Vehicle
{
protected: 
    int avgSpeed = 0;
    int mileage = 0;

public:

    bool engineRunning = true;
    string terrain = " ";
    
    virtual void Drive() = 0;
    int GetMileage();
};
