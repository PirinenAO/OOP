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

const int MAX_CUSTOMER_CAPACITY = 100;
const int MAX_ROOM_CAPACITY = 100;

// CLASSES

class ROOM
{
    int room_number;
    string area;
    string type;
    int price; // per night
    int status;
    string customer;

public:
    void set_info(int room_number, string area, string type, int price);
    void print_info();
    string return_status();
    void setup_rooms(ROOM *rooms, int number_of_rooms);
    void change_status(string customer);
    int return_price(int length_of_stay);
    int return_room_number();
};

class CUSTOMER
{
    string name;
    string address;
    int room_number;
    string arrival_date;
    int length_of_stay;
    int price;

public:
    void print_info();
    void set_info(string name, string address, string arrival_date, int length_of_stay, int room_number, int price);
};

class HOTEL
{
    string name;
    string address;
    int number_of_stars;
    int number_of_rooms;
    int number_of_customers;

public:
    void print_info();
    void set_info(string name, string address, int number_of_stars);
    void add_room();
    void add_customer();
    void print_free_rooms();
    void print_reserved_rooms();
    void reserve_room(int room_number, string customer);
    void print_customers();
    bool check_if_all_booked();
    int find_price(int, int);
    ROOM *rooms[MAX_ROOM_CAPACITY];
    CUSTOMER *customers[MAX_CUSTOMER_CAPACITY];
};

// METHODS

// HOTEL METHODS

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
    this->number_of_customers = 0; // initialization of customers
    this->number_of_rooms = 0;     // initialization of rooms
}

void HOTEL::add_room()
{
    this->rooms[number_of_rooms] = new ROOM;

    int room_number;
    string area;
    string type;
    int price;
    int counter;
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

    this->rooms[number_of_rooms]->set_info(room_number, area, type, price);
    this->number_of_rooms++;
}

void HOTEL::add_customer()
{
    string name;
    string address;
    int room_number;
    string arrival_date;
    int length_of_stay;
    int counter;
    int price;

    this->customers[number_of_customers] = new CUSTOMER;

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
    this->customers[number_of_customers]->set_info(name, address, arrival_date, length_of_stay, room_number, price);
    this->number_of_customers++;
}

int HOTEL::find_price(int length_of_stay, int room_number)
{
    int counter;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (this->rooms[counter]->return_room_number() == room_number)
        {
            return rooms[counter]->return_price(length_of_stay);
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
        customers[counter]->print_info();
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
        if (rooms[counter]->return_status() == "FREE")
        {
            rooms[counter]->print_info();
            cout << "--------------------" << endl;
        }
    }
    cout << endl;
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
        if (rooms[counter]->return_status() == "RESERVED")
        {
            rooms[counter]->print_info();
            cout << "--------------------" << endl;
        }
    }
}

void HOTEL::reserve_room(int room_number, string customer)
{
    int counter;
    for (counter = 0; counter < this->number_of_rooms; counter++)
    {
        if (rooms[counter]->return_room_number() == room_number)
        {
            rooms[counter]->change_status(customer);
            cout << endl
                 << "--------------------" << endl;
            cout << "Room reserved succesfully" << endl;
        }
    }
}

// ROOM METHODS

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
    cout << "Room " << room_number << ": " << endl;
    cout << "Status: " << return_status() << endl;
    cout << "Area: " << area << endl;
    cout << "Type: " << type << endl;
    cout << "Price per night: " << price << endl;
    cout << "Customer: " << customer << endl;
}

void ROOM::set_info(int room_number, string area, string type, int price)
{
    this->room_number = room_number;
    this->area = area;
    this->type = type;
    this->price = price;
    this->status = 1;
}

// CUSTOMER METHODS

void CUSTOMER::print_info()
{
    cout << "Customer: " << this->name << endl;
    cout << "Address: " << this->address << endl;
    cout << "Arrival date: " << this->arrival_date << endl;
    cout << "Number of nights: " << this->length_of_stay << endl;
    cout << "Room number: " << this->room_number << endl;
    cout << "Total price: " << this->price << endl;
}

void CUSTOMER::set_info(string name, string address, string arrival_date, int length_of_stay, int room_number, int price)
{
    this->name = name;
    this->address = address;
    this->room_number = room_number;
    this->arrival_date = arrival_date;
    this->length_of_stay = length_of_stay;
    this->price = price;
}

int main(void)
{
    bool all_booked;
    HOTEL *hotel;
    hotel = new HOTEL;

    hotel->set_info("FORENOM", "Kauppakatu 2", 3); // initializing hotel name, address and number of stars

    char c;
    while (c != 'q' || c != 'Q')
    {
        cout << endl;
        cout << "#######################" << endl;
        cout << "A to add room" << endl
             << "B to add customer" << endl
             << "C to display customers" << endl;
        cout << "F to display free rooms" << endl
             << "R to display reserved rooms" << endl
             << "H to display hotel information" << endl
             << "Q to quit " << endl;
        cout << "#######################" << endl;
        cin >> c;
        if (c == 'a' || c == 'A')
        {
            hotel->add_room();
        }
        else if (c == 'c' || c == 'C')
        {
            hotel->print_customers();
        }
        else if (c == 'f' || c == 'F')
        {
            hotel->print_free_rooms();
        }
        else if (c == 'r' || c == 'R')
        {
            hotel->print_reserved_rooms();
        }
        else if (c == 'q' || c == 'Q')
        {
            delete[] hotel;
            delete[] hotel->rooms;
            delete[] hotel->customers;
            break;
        }
        else if (c == 'b' || c == 'B')
        {
            all_booked = hotel->check_if_all_booked(); // checking if there is free rooms left
            if (all_booked)
            {
                cout << endl;
                cout << "NO FREE ROOMS LEFT" << endl;
            }
            else
            {
                hotel->add_customer();
            }
        }
        else if (c == 'h' || c == 'H')
        {
            hotel->print_info();
        }
        cin.ignore();
    }
}
