#include "Boat.h"
#include <iostream>

Boat::Boat(int numMiles)
{
    terrain = "Water";
    avgSpeed = 30;
    mileage = numMiles;
}

void Boat::Drive() 
{
    if (engineRunning)
    {
        mileage += avgSpeed;
    }
    else
    {
        cout << "Start your engine first!" << endl;
    }
}