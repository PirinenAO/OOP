/*A program for managing the information of rooms and customers in a hotel.
Define Room, Customer and Hotel classes so that a hotel object can hold arrays
of Room and Customer objects.
The important information for the hotel is: name, address, number of stars and number of rooms.
The important information for room is: number, area, type (single, double, suite) and price per night.
The important information for customer is: name, address and room number, arrival date and the length of stay in nights.
Define necessary functions in each class so that it would be easily possible to reserve and free rooms and also
get room and customer information and the amount of money each customer will pay after his/her
stay. It should also be possible to print out a list of customers and their room information,
as well as a list of free and reserved rooms.*/
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// DECLARING CLASSES

class ROOM
{
    int room_number;
    string area;
    string type;
    int price;      // per night
    int status = 1; // 1 = free, 0 = reserved

public:
    void set_info(int room_number, string area, string type, int price);
    void print_info();
    string return_status();
    void setup_rooms(ROOM *rooms, int number_of_rooms);
    void change_status();
    int return_number();
};

class CUSTOMER
{
    string name;
    string address;
    int room_number;
    string arrival_date;
    int length_of_stay;

public:
    void print_info();
    void set_info(string name, string address, string arrival_date, int length_of_stay, int room_number);
};

class HOTEL
{
    string name;
    string address;
    int number_of_stars;
    int number_of_rooms;
    int number_of_customers;

public:
    void set_info(string name, string address, int number_of_stars, int number_of_rooms);
    void add_rooms();
    void add_customer();
    void print_free_rooms(int number_of_rooms);
    void print_reserved_rooms(int number_of_rooms);
    void reserve_room(int room_number);
    void print_customers();
    ROOM *rooms;
    CUSTOMER *customers;
};

// DEFINING METHODS

// HOTEL METHODS

void HOTEL::set_info(string name, string address, int number_of_stars, int number_of_rooms)
{
    this->name = name;
    this->address = address;
    this->number_of_stars = number_of_stars;
    this->number_of_rooms = number_of_rooms;
}

void HOTEL::add_rooms()
{
    this->rooms = new ROOM[number_of_rooms];
}

void HOTEL::add_customer()
{
    this->customers = new CUSTOMER;

    string name;
    string address;
    int room_number;
    string arrival_date;
    int length_of_stay;

    cin.ignore();
    cout << endl;
    cout << "Customer name: " << endl;
    getline(cin, name);
    cout << "Customers address: " << endl;
    getline(cin, address);
    cout << "Arrival date: " << endl;
    getline(cin, arrival_date);
    cout << "Length of the stay: " << endl;
    cin >> length_of_stay;
    cout << endl;
    cout << "List of free rooms: " << endl;
    this->print_free_rooms(this->number_of_rooms);
    cin.ignore();
    cout << "Select room: " << endl;
    cin >> room_number;

    this->reserve_room(room_number);

    customers->set_info(name, address, arrival_date, length_of_stay, room_number);
    this->number_of_customers++;
}

void HOTEL::print_customers()
{
    int counter;
    cout << "--------------------" << endl;
    for (counter = 0; counter < number_of_customers; counter++)
    {
        customers[counter].print_info();
        cout << "--------------------" << endl;
    }
}

void HOTEL::print_free_rooms(int number_of_rooms)
{
    int counter;
    cout << "--------------------" << endl;
    for (counter = 0; counter < number_of_rooms; counter++)
    {
        if (rooms[counter].return_status() == "FREE")
        {
            rooms[counter].print_info();
            cout << "--------------------" << endl;
        }
    }
}

void HOTEL::print_reserved_rooms(int number_of_rooms)
{
    int counter;
    cout << "--------------------" << endl;
    for (counter = 0; counter < number_of_rooms; counter++)
    {
        if (rooms[counter].return_status() == "RESERVED")
        {
            rooms[counter].print_info();
            cout << "--------------------" << endl;
        }
    }
}

void HOTEL::reserve_room(int room_number)
{
    int counter;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (rooms[counter].return_number() == room_number)
        {
            rooms[counter].change_status();
        }
    }
}
// ROOM METHODS
int ROOM::return_number()
{
    return this->room_number;
}

void ROOM::setup_rooms(ROOM *rooms, int number_of_rooms)
{
    int room_number;
    string area;
    string type;
    int price;
    int counter;

    cout << "ROOM SETUP" << endl;
    for (counter = 0; counter < number_of_rooms; counter++)
    {
        cout << endl;
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

        rooms[counter].set_info(room_number, area, type, price);
    }
}

void ROOM::set_info(int room_number, string area, string type, int price)
{
    this->room_number = room_number;
    this->area = area;
    this->type = type;
    this->price = price;
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

void ROOM::print_info()
{
    cout << "Room " << room_number << ": " << endl;
    cout << "Status: " << return_status() << endl;
    cout << "Area: " << area << endl;
    cout << "Type: " << type << endl;
    cout << "Price: " << price << endl;
}

void ROOM::change_status()
{
    if (this->status == 1)
    {
        this->status = 0;
    }
    else
    {
        this->status = 1;
    }
}

// CUSTOMER METHODS

void CUSTOMER::print_info()
{
    cout << "name : " << this->name << endl;
    cout << "address: " << this->address << endl;
    cout << "arrival date: " << this->arrival_date << endl;
    cout << "number of nights: " << this->length_of_stay << endl;
    cout << "room number: " << this->room_number << endl;
}

void CUSTOMER::set_info(string name, string address, string arrival_date, int length_of_stay, int room_number)
{
    this->name = name;
    this->address = address;
    this->room_number = room_number;
    this->arrival_date = arrival_date;
    this->length_of_stay = length_of_stay;
}

int main(void)
{
    int size = 1;
    string name = "hotel";
    string address = "kauppakatu 2";
    int number_of_stars = 2;
    int number_of_rooms = 2;
    int room_number;
    string area;
    string type;
    int price;
    int number_of_customers;
    char ch;

    HOTEL *hotel;

    hotel = new HOTEL;
    hotel->set_info(name, address, number_of_stars, number_of_rooms);
    hotel->add_rooms();
    hotel->rooms->setup_rooms(hotel->rooms, number_of_rooms);

    hotel->add_customer();

    hotel->print_customers();
}
