#include "Plane.h"
#include <iostream>

Plane::Plane(int numMiles)
{
    terrain = "Air";
    avgSpeed = 200;
    mileage = numMiles;
}

void Plane::Drive() 
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