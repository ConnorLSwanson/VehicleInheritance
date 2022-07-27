#include "Car.h"

Car::Car(int numMiles)
{
    terrain = "Ground";
    avgSpeed = 60;
    mileage = numMiles;
}

void Car::Drive() 
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