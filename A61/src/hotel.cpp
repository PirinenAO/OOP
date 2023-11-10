#include "../include/hotel.h"
#include <iostream>
#include <string>
using namespace std;

void HOTEL::print_info()
{

    cout << endl
         << "--------------------" << endl;
    cout << "HOTEL INFORMATION" << endl;
    cout << "--------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Number of stars: " << number_of_stars << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Number of customers: " << number_of_customers << endl;
    cout << "--------------------" << endl;
}

bool HOTEL::check_if_all_booked()
{
    if (number_of_rooms == number_of_customers)
    {
        return true;
    }

    return false;
}

void HOTEL::set_info(string name, string address, int number_of_stars)
{
    this->name = name;
    this->address = address;
    this->number_of_stars = number_of_stars;
    this->number_of_customers = 1; // initialization of customers
    this->number_of_rooms = 1;     // initialization of rooms
    this->rooms = new ROOM[number_of_rooms];
    this->customers = new CUSTOMER[number_of_customers];
}

void HOTEL::add_room()
{
    this->number_of_rooms++;

    ROOM *temp;
    try
    {
        temp = new ROOM[number_of_rooms];
    }
    catch (bad_alloc &xa)
    {
        cout << "memory allocation failed for room" << endl;
        return;
    }

    int room_number;
    string area;
    string type;
    int price;
    cout << endl
         << "--------------------" << endl;
    cout << "ROOM SETUP" << endl;
    cout << "--------------------" << endl;

    cout << "Room number: " << endl;
    cin >> room_number;
    cin.ignore();
    cout << "Area: " << endl;
    getline(cin, area);
    cout << "Room type: " << endl;
    getline(cin, type);
    cout << "Price per night: " << endl;
    cin >> price;
    cout << endl;

    temp[0].set_info(room_number, area, type, price);

    for (int i = 1; i < number_of_rooms; i++)
    {
        temp[i] = this->rooms[i - 1];
    }

    rooms = temp;
    // this->rooms[number_of_rooms - 1].set_info(room_number, area, type, price);
    // this->number_of_rooms++;
}

void HOTEL::add_customer()
{
    // this->number_of_customers++;

    CUSTOMER *temp;

    string name;
    string address;
    int room_number;
    string arrival_date;
    int length_of_stay;
    int counter;
    int price;

    try
    {
        temp = new CUSTOMER[number_of_customers];
    }
    catch (bad_alloc &xa)
    {
        cout << "memory allocation failed for customer" << endl;
        return;
    }

    // this->customers[number_of_customers] = new CUSTOMER;

    cin.ignore();
    cout << endl
         << "--------------------" << endl;
    cout << "CUSTOMER SETUP" << endl;
    cout << "--------------------" << endl;
    cout << "Customers name: " << endl;
    getline(cin, name);
    cout << "Customers address: " << endl;
    getline(cin, address);
    cout << "Arrival date: " << endl;
    getline(cin, arrival_date);
    cout << "Length of the stay: " << endl;
    cin >> length_of_stay;
    cout << endl;
    this->print_free_rooms();
    cout << "Select room: " << endl;
    cin >> room_number;
    this->reserve_room(room_number, name);

    price = find_price(length_of_stay, room_number);

    cout << endl;
    cout << "Total price is: " << price << endl;
    cout << "--------------------" << endl;

    temp[0].set_info(name, address, arrival_date, length_of_stay, room_number, price);

    for (int i = 1; i < number_of_customers; i++)
    {
        temp[i] = this->customers[i - 1];
    }

    this->number_of_customers++;
}

int HOTEL::find_price(int length_of_stay, int room_number)
{
    int counter;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (this->rooms[counter].return_room_number() == room_number)
        {
            return rooms[counter].return_price(length_of_stay);
        }
    }

    return 0;
}

void HOTEL::print_customers()
{
    int counter;
    cout << endl
         << "--------------------" << endl;
    cout << "LIST OF CURRENT CUSTOMERS" << endl;
    cout << "--------------------" << endl;
    for (counter = 0; counter < number_of_customers; counter++)
    {
        customers[counter].print_info();
        cout << "--------------------" << endl;
    }
}

void HOTEL::print_free_rooms()
{
    int counter;
    cout << endl
         << "--------------------" << endl;
    cout << "LIST OF FREE ROOMS" << endl;
    cout << "--------------------" << endl;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (rooms[counter].return_status() == "FREE")
        {
            rooms[counter].print_info();
            cout << "--------------------" << endl;
        }
    }
}

void HOTEL::print_reserved_rooms()
{
    int counter;
    cout << endl
         << "--------------------" << endl;
    cout << "LIST OF RESERVED ROOMS" << endl;
    cout << "--------------------" << endl;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (rooms[counter].return_status() == "RESERVED")
        {
            rooms[counter].print_info();
            cout << "--------------------" << endl;
        }
    }
}

void HOTEL::reserve_room(int room_number, string customer)
{
    int counter;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (rooms[counter].return_room_number() == room_number)
        {
            rooms[counter].change_status(customer);
            cout << endl
                 << "--------------------" << endl;
            cout << "Room reserved succesfully" << endl;
        }
    }
}