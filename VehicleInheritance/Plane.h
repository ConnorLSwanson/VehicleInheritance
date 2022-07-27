#pragma once
#include "Vehicle.h"

class Plane : public Vehicle
{
public:
    Plane(int numMiles);
    void Drive() override;    
};