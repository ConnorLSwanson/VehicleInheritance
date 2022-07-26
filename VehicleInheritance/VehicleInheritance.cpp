// VehicleInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Connor Swanson
// Activision Blizzard
// 7/21/2022

#include <iostream>
#include <string>
#include <time.h>
#include "Vehicles.h"

using namespace std;

string PickVehicle();
void PrintMileage(string vhcl, Car* pCar, Boat* pBoat, Plane* pPlane);
string PickTerrain();
void DriveVehicle(string vhcl, string terrain, Car* pCar, Boat* pBoat, Plane* pPlane);
void MainGameLoop(string vhcl);
bool KeepPlaying();

int main()
{
    srand((unsigned)time(0));

    Car myCar = Car(rand() % 100000);
    Boat myBoat = Boat(rand() % 100000);
    Plane myPlane = Plane(rand() % 500000);
    string pickedVehicle;
    string pickedTerrain;

    cout << "Welcome to the vehicle game!  Pick a vehicle and drive it!" << endl;

    bool playGame = true;
    do
    {        
        pickedVehicle = PickVehicle();

        // get mileage from vehicle
        PrintMileage(pickedVehicle, &myCar, &myBoat, &myPlane);

        // Pick terrain
        pickedTerrain = PickTerrain();

        // if vehicle can drive, then drive
        DriveVehicle(pickedVehicle, pickedTerrain, &myCar, &myBoat, &myPlane);


        playGame = KeepPlaying();
    } while (playGame);
}


string PickVehicle()
{
    char vehicle;

    cout << "You can select 'B' for Boat, 'C' for Car, or 'P' for Plane" << endl;

    cin >> vehicle;

    switch (vehicle)
    {
    case 'b':
    case 'B':
        cout << "You have selected Boat!" << endl;
        return "boat";
        break;

    case 'c':
    case 'C':
        cout << "You have selected Car!" << endl;
        return "car";
        break;

    case 'p':
    case 'P':
        cout << "You have selected Plane!" << endl;
        return "plane";
        break;

    default:
        cout << "Please select a valid response." << endl;
        break;
    }
}


void PrintMileage(string vhcl, Car* pCar, Boat* pBoat, Plane* pPlane)
{
    if (vhcl == "boat")
    {
        cout << "The boat has " << pBoat->GetMileage() << " miles on it!" << endl;
    }
    else if (vhcl == "car")
    {
        cout << "The car has " << pCar->GetMileage() << " miles on it!" << endl;
    }
    else if (vhcl == "plane")
    {
        cout << "The plane has " << pPlane->GetMileage() << " miles on it!" << endl;
    }
}


string PickTerrain()
{
    bool valid = false;
    string selection;
    do {
        int pick = 0;
        cout << "Where are you going to drive your vehicle? (Pick a number)" << endl;
        cout << "1. Roads" << endl;
        cout << "2. Water" << endl;
        cout << "3. Air" << endl;
        cin >> pick;

        switch (pick) {
        case 1:
            selection = "road";
            valid = true;
            break;
        case 2:
            selection = "water";
            valid = true;
            break;
        case 3: 
            selection = "air";
            valid = true;
            break;
        default:
            cout << "Please pick a valid response." << endl;
            valid = false;
        }
    } while (!valid);
    
    return selection;
}


void DriveVehicle(string vhcl, string terrain, Car* pCar, Boat* pBoat, Plane* pPlane)
{
    // I would like to know if there is a more efficient way of writing this section. Thanks!

    if (terrain == "road")
    {
        if (vhcl == "boat")
        {
            cout << "Your boat grinds to a halt as the propellers damage themselves against the asphalt." << endl;
            cout << "What did you think was going to happen?" << endl;
        }
        else if (vhcl == "car")
        {
            cout << "You take a casual drive down the road!" << endl;
            pCar->Drive();
        }
        else if (vhcl == "plane")
        {
            cout << "You boldly drive your plane on the road, ignoring all the cars honking at you." << endl;
            cout << "You don't make it far before you are arrested." << endl;
        }
    }
    else if (terrain == "water")
    {
        if (vhcl == "boat")
        {
            cout << "It's a nice day for a boat ride!" << endl;
            pBoat->Drive();
        }
        else if (vhcl == "car")
        {
            cout << "You do not have one of those amphibious vehicles." << endl; 
            cout << "Your car sinks." << endl;
        }
        else if (vhcl == "plane")
        {
            cout << "Oceanic Flight 815 crashes and strands 72 passengers on a remote island in the tropical Pacific." << endl;
        }
    }
    else if (terrain == "air")
    {
        if (vhcl == "boat")
        {
            cout << "Stop it." << endl;
        }
        else if (vhcl == "car")
        {
            cout << "Filling your truck with jet fuel does not make it behave like a jet!" << endl;
        }
        else if (vhcl == "plane")
        {
            cout << "You take a nice tour over the mountains before heading back for a clean landing" << endl;
            pPlane->Drive();
        }
    }


}


void MainGameLoop(string vhcl)
{
    int action = 0;

    cout << "You have selected the " << vhcl << "!  Cool!" << endl;
    cout << "What would you like to do? (pick a number)" << endl;
    cout << "1. Start engine." << endl;
    cout << "2. Stop engine." << endl;
    cout << "3. Drive!" << endl;
    cin >> action;

    switch (action)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    }

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