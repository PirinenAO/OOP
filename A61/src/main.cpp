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
#include "../include/room.h"
#include "../include/customer.h"
#include "../include/hotel.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    bool all_booked; // boolean to tell if there is free rooms left

    HOTEL *hotel;
    hotel = new HOTEL;

    hotel->set_info("FORENOM", "Kauppakatu 2", 3); // initializing hotel name object

    char c;

    while (true)
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
