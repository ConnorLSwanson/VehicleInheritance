#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(int numMiles);
    void Drive() override;
};