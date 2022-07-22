// VehicleInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Connor Swanson
// Activision Blizzard
// 7/21/2022

#include <iostream>
#include <string>

using namespace std;

// write class for vehicle
    // virtual Drive()
    // avg speed
    // mileage
    // speed
    // driver
    // number of passengers
class Vehicle
{
public:

    double avgSpeed = 0;
    int mileage = 0;
    bool engineRunning = false;
    string terrain = " ";

    virtual void Drive() = 0;

    void StartEngine()
    {
        engineRunning = true;
    }

    void StopEngine()
    {
        engineRunning = false;
    }
};



// write class for Car
    // Drive() override
    // number of wheels
class Car : Vehicle
{
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


// write class for Boat
    // Drive() override
    // type of boat (speed boat, fishing boat, pontoon, yacht)
class Boat : Vehicle
{
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



// write class for Plane
    // Drive() override
    // type of plane (smol plane, big plane, helicopter)
class Plane : Vehicle
{
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


bool KeepPlaying();

int main()
{


    bool playGame = true;
    do
    {


        playGame = KeepPlaying();
    } while (playGame);
}

bool KeepPlaying()
{
    bool validResponse = false;
    char a;
    cout << "Do you want to keep playing? 'Y' or 'N'" << endl;
    cin >> a;
    
    do 
    {
        switch (a)
        {
        case 'Y':
        case 'y':
            validResponse = true;
            return true;

        case 'N':
        case 'n':
            validResponse = true;
            return false;

        default:
            cout << "That is not a valid response." << endl;
            validResponse = false;
            break;
        }
    } while (validResponse);    
}