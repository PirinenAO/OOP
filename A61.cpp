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
};

class HOTEL
{
    string name;
    string address;
    int number_of_stars;
    int number_of_rooms;

public:
    void set_info(string name, string address, int number_of_stars, int number_of_rooms);
    void add_rooms();
    void print_free_rooms();
    void print_reserved_rooms();
    ROOM *rooms;
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

void HOTEL::print_free_rooms()
{
    int counter;
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

// ROOM METHODS

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

    HOTEL *hotel;

    hotel = new HOTEL;

    // SETUP HOTEL
    /*
    cout << "HOTEL SETUP" << endl;
    cout << "Name :" << endl;
    getline(cin, name);
    cout << "Address: " << endl;
    getline(cin, address);
    cout << "Number of stars" << endl;
    cin >> number_of_stars;
    cout << "Number of rooms" << endl;
    cin >> number_of_rooms;
    cout << endl;
    */

    hotel->set_info(name, address, number_of_stars, number_of_rooms);

    hotel[0].add_rooms();
    hotel->rooms[0].setup_rooms(hotel->rooms, number_of_rooms);
    hotel->rooms[1].change_status();
    hotel[0].print_free_rooms();
    hotel[0].print_reserved_rooms();

    // hotel->rooms[0].print_info();
}