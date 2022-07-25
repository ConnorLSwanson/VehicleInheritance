// VehicleInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Connor Swanson
// Activision Blizzard
// 7/21/2022

#include <iostream>
#include <string>
#include <time.h>
#include "Vehicles.h"

using namespace std;

string InitializeGame();
void MainGameLoop(string vhcl);
bool KeepPlaying();

int main()
{
    srand((unsigned)time(0));

    Car* pMyCar = new Car(rand() % 100000);
    Boat* pMyBoat = new Boat(rand() % 100000);
    Plane* pMyPlane = new Plane(rand() % 500000);

    bool playGame = true;
    do
    {
        string pickedVehicle;
        pickedVehicle = InitializeGame();

        MainGameLoop(pickedVehicle);

        playGame = KeepPlaying();
    } while (playGame);
}


string InitializeGame()
{
    char vehicle;

    cout << "Welcome to the vehicle game!  Pick a vehicle and drive it!" << endl;
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