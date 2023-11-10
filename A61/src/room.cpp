#include "../include/room.h"
#include <iostream>
#include <string>
using namespace std;

int ROOM::return_price(int length_of_stay)
{

    return this->price * length_of_stay;
}

int ROOM::return_room_number()
{
    return this->room_number;
}

string ROOM::return_status()
{
    if (status == 1)
    {
        return "FREE";
    }
    else
    {

        return "RESERVED";
    }
}

void ROOM::change_status(string customer)
{
    if (this->status == 1)
    {
        this->status = 0;
        this->customer = customer; // adding customer to current room
    }
    else
    {
        this->status = 1;
    }
}

void ROOM::print_info()
{
    cout << "Room " << this->room_number << ": " << endl;
    cout << "Status: " << this->return_status() << endl;
    cout << "Area: " << this->area << endl;
    cout << "Type: " << this->type << endl;
    cout << "Price per night: " << this->price << endl;
    cout << "Customer: " << this->customer << endl;
}

void ROOM::set_info(int room_number, string area, string type, int price)
{
    this->room_number = room_number;
    this->area = area;
    this->type = type;
    this->price = price;
    this->status = 1;
}