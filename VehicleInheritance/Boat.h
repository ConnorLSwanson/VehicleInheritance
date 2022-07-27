#pragma once
#include "Vehicle.h"


class Boat : public Vehicle
{
public:
    Boat(int numMiles);
    void Drive() override;    
};