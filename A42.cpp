/*A program in which you define two data structures: room and customer. The fields for room should be: room_id, type (single, double, ...),
status (free or occupied) and price per night. The fields for customer should be: name, room_id and number_of_nights.
The program must ask the number of rooms and customers from the user, allocate memory for them and read data for them.
Make sure to enter room data first and then ask for customer information. While assigning room id to a customer,
the program must check whether the room, which is going to be assigned is free or not and then assign it to the customer if it is free.
After reading the data, the program must print a list which shows which room (room_id) is occupied by which customer and displays the customer information.*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int CUSTOMER_AMOUNT = 3;
const int ROOM_AMOUNT = 5;

struct ROOM
{
    int room_id;
    int room_type;           // room type (single,double or triple)
    unsigned int status : 1; // 0 equals to free, 1 equals to occupied;
    int price_per_night;
};

struct CUSTOMER
{
    string name;
    int room_id;
    int number_of_nights;
};

void addRooms(ROOM *ptr);
void addCustomers(CUSTOMER *ptr1, ROOM *ptr2);
void printSummary(CUSTOMER *ptr1, ROOM *ptr2);
int findRoom(int, ROOM *ptr);

int main(void)
{
    ROOM *rooms;
    CUSTOMER *customers;

    try
    {
        rooms = new ROOM[ROOM_AMOUNT];
        customers = new CUSTOMER[CUSTOMER_AMOUNT];
    }
    catch (bad_alloc &xa)
    {
        cout << "Memory allocation Failed!";
    }

    addRooms(rooms);
    addCustomers(customers, rooms);
    printSummary(customers, rooms);
}

void addRooms(ROOM *ptr)
{
    int i;
    for (i = 0; i < ROOM_AMOUNT; i++)
    {
        ptr[i].room_id = 1000 + i;
        ptr[i].room_type = 1;
        ptr[i].price_per_night = 100;
        ptr[i].status = 0;
    }
}

void addCustomers(CUSTOMER *ptr1, ROOM *ptr2)
{
    int nights, room_type, i;
    string name_input;

    for (i = 0; i < CUSTOMER_AMOUNT; i++)
    {
        cout
            << endl;
        cout << "name: " << endl;
        cin >> name_input;
        ptr1[i].name = name_input;

        cout << "nights: " << endl;
        cin >> nights;
        ptr1[i].number_of_nights = nights;

        cout << "room type: " << endl;
        cin >> room_type;

        // assigning room;
        int room_id = findRoom(room_type, ptr2);
        ptr1[i].room_id = room_id;
    }
}

int findRoom(int type, ROOM *ptr)
{
    for (int i = 0; i < ROOM_AMOUNT; i++)
    {
        if (ptr[i].room_type == type && ptr[i].status == 0)
        {
            ptr[i].status = 1; // status to 1, so no double bookings
            return ptr[i].room_id;
        }
    }

    return 0;
}

void printSummary(CUSTOMER *ptr1, ROOM *ptr2)
{
    bool customer;
    for (int i = 0; i < ROOM_AMOUNT; i++)
    {
        customer = false;
        cout << endl;
        cout << "Room ID: " << ptr2[i].room_id << endl;
        cout << "Customer: ";
        for (int j = 0; j < CUSTOMER_AMOUNT; j++)
        {
            if (ptr2[i].room_id == ptr1[j].room_id)
            {
                cout << ptr1[j].name << endl;
                cout << "Nights: " << ptr1[j].number_of_nights << endl;
                cout << "Price: " << ptr2[i].price_per_night * ptr1[j].number_of_nights << "$" << endl;

                customer = true;
                j = CUSTOMER_AMOUNT;
            }
        }

        if (!customer)
        {
            cout << "no customer" << endl;
            cout << "Nights: -" << endl;
            cout << "Price: -" << endl;
        }
    }
}
