#pragma once
#include <string>

using namespace std;

class Vehicle
{
public:

    int avgSpeed = 0;
    int mileage = 0;
    bool engineRunning = false;
    string terrain = " ";
    bool canDrive;

    virtual void Drive() = 0;

    void StartEngine()
    {
        engineRunning = true;
    }

    void StopEngine()
    {
        engineRunning = false;
    }

    void CheckTerrain()
    {
        if (terrain == " ")
        {
            cout << "You need to choose where you are going to drive!" << endl;
            ChangeTerrain();
        }
        else
        {
            cout << "You are driving on the " << terrain << "!  Wow!" << endl;
        }
    }


    void ChangeTerrain()
    {
        cout << "Where are you going to take your vehicle?  (Select a number)" << endl;
        cout << "1. Roads." << endl;
        cout << "2. Water." << endl;
        cout << "3. Air" << endl;
        int selection = 0;
        cin >> selection;

        switch (selection)
        {
        case 1:
            terrain = "road";
            break;

        case 2: 
            terrain = "water";
            break;

        case 3: 
            terrain = "air";
            break;

        default:
            system("cls");
            cout << "Please select a valid input." << endl;
        }
    }
};

class Car : Vehicle
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


class Boat : Vehicle
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


class Plane : Vehicle
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