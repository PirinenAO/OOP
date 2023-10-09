/*A program in which you define two data structures: room and customer. The fields for room should be: room_id, type (single, double, ...),
status (free or occupied) and price per night. The fields for customer should be: name, room_id and number_of_nights.
The program must ask the number of rooms and customers from the user, allocate memory for them and read data for them.
Make sure to enter room data first and then ask for customer information. While assigning room id to a customer,
the program must check whether the room, which is going to be assigned is free or not and then assign it to the customer if it is free.
After reading the data, the program must print a list which shows which room (room_id) is occupied by which customer and displays the customer information.*/
#include <iostream>
#include <string>
using namespace std;

// variables
int CUSTOMER_AMOUNT;
int ROOM_AMOUNT;

// structs
struct ROOM
{
    int room_id;
    unsigned int room_type : 3; // room type (single,double or triple)
    unsigned int status : 1;    // 0 equals to free, 1 equals to occupied;
    int price_per_night;
};

struct CUSTOMER
{
    string name;
    int room_id;
    int number_of_nights;
};

// declaring functions
void addRooms(ROOM *ptr);
void addCustomers(CUSTOMER *ptr1, ROOM *ptr2);
void printSummary(CUSTOMER *ptr1, ROOM *ptr2);
int findRoom(int, ROOM *ptr);

// main function
int main(void)
{

    ROOM *rooms;
    CUSTOMER *customers;

    // setting up rooms
    cout << "How many rooms to add?" << endl;
    cin >> ROOM_AMOUNT;
    try
    {
        rooms = new ROOM[ROOM_AMOUNT];
    }
    catch (bad_alloc &xa)
    {
        cout << "Memory allocation Failed!";
    }
    addRooms(rooms);

    // adding customers
    cout << "---------------------" << endl;
    cout << "How many customers?" << endl;
    cin >> CUSTOMER_AMOUNT;
    try
    {

        customers = new CUSTOMER[CUSTOMER_AMOUNT];
    }
    catch (bad_alloc &xa)
    {
        cout << "Memory allocation Failed!";
    }
    addCustomers(customers, rooms);

    // printing the rooms and customers
    printSummary(customers, rooms);

    // deleting reserved memory addresses
    rooms = NULL;
    customers = NULL;
    delete[] rooms;
    delete[] customers;
}

// defining functions

// function to setup rooms for the system
void addRooms(ROOM *rooms)
{
    // variables
    int i, room_type, price_per_night;

    // loop for room setups
    for (i = 0; i < ROOM_AMOUNT; i++)
    {
        cout << "---------------------" << endl;
        rooms[i].room_id = 1000 + i;
        cout << "Setting up room ID " << rooms[i].room_id << endl;
        cout << "Set room type (Single = 1, Double = 2 or Triple = 3)" << endl;
        cin >> room_type;
        rooms[i].room_type = room_type;
        cout << "Set price per night: " << endl;
        cin >> price_per_night;
        rooms[i].price_per_night = price_per_night;
        rooms[i].status = 0;
    }
}

// function to add customer data
void addCustomers(CUSTOMER *customers, ROOM *rooms)
{
    // variables
    int nights, room_type, i;
    string name_input;

    // loop for customer setups
    for (i = 0; i < CUSTOMER_AMOUNT; i++)
    {
        // clearing input buffer to avoid issues
        cin.ignore();
        cout << "---------------------" << endl;
        cout << "Customers name: " << endl;
        getline(cin, name_input);
        customers[i].name = name_input;

        cout << "How many nights: " << endl;
        cin >> nights;
        customers[i].number_of_nights = nights;

        cout << "Room type: " << endl;
        cin >> room_type;

        // searching for room matching users needs;
        int room_id = findRoom(room_type, rooms);
        if (room_id == 0)
        {
            cout << endl
                 << "No rooms found" << endl;
        }
        else
        {
            customers[i].room_id = room_id;
        }
    }
}

// function to find matching room for the user
int findRoom(int type, ROOM *rooms)
{
    // looping through all rooms
    for (int i = 0; i < ROOM_AMOUNT; i++)
    {
        // if the room type matches, and the rooms if free
        if (rooms[i].room_type == type && rooms[i].status == 0)
        {
            rooms[i].status = 1;     // status to 1, so no double bookings
            return rooms[i].room_id; // returning rooms id
        }
    }

    // if room was not found, return 0
    return 0;
}

// function to print out the rooms and customers at the end
void printSummary(CUSTOMER *customers, ROOM *rooms)
{
    bool customer;
    cout << "---------------------" << endl;
    // looping through all rooms and printing their data
    for (int i = 0; i < ROOM_AMOUNT; i++)
    {
        customer = false;
        cout << "Room ID: " << rooms[i].room_id << endl;
        cout << "Room type: " << rooms[i].room_type << endl;
        cout << "Customer: ";
        // finding the customer name for the current room
        for (int j = 0; j < CUSTOMER_AMOUNT; j++)
        {
            if (rooms[i].room_id == customers[j].room_id)
            {
                cout << customers[j].name << endl;
                cout << "Nights: " << customers[j].number_of_nights << endl;
                cout << "Price: " << rooms[i].price_per_night * customers[j].number_of_nights << "$" << endl;

                customer = true;
                break;
            }
        }
        // if there is no customer
        if (!customer)
        {
            cout << "no customer" << endl;
            cout << "Nights: -" << endl;
            cout << "Price: -" << endl;
        }
        cout << "---------------------" << endl;
    }
}
