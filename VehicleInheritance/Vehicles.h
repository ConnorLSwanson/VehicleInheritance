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

    int GetMileage()
    {
        return mileage;
    }
};

class Car : public Vehicle
{
public:
    Car(int numMiles)
    {
        terrain = "Ground";
        avgSpeed = 60;
        mileage = numMiles;
    }

    void Drive() override
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
};


class Boat : public Vehicle
{
public:
    Boat(int numMiles)
    {
        terrain = "Water";
        avgSpeed = 30;
        mileage = numMiles;
    }

    void Drive() override
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
};


class Plane : public Vehicle
{
public:
    Plane(int numMiles)
    {
        terrain = "Air";
        avgSpeed = 200;
        mileage = numMiles;
    }

    void Drive() override
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
};