/*A program for managing the information of rooms and customers in a hotel.
Define Room, Customer and Hotel classes so that a hotel object can hold arrays
of Room and Customer objects.
The important information for the hotel is: name, address, number of stars and number of rooms.
The important information for rooms is: number, area, type (single, double, suite) and price per night.
The important information for customers is: name, address and room number, arrival date and the length of stay in nights.
Define necessary functions in each class so that it would be easily possible to reserve and free rooms and also
get room and customer information and the amount of money each customer will pay after his/her
stay. It should also be possible to print out a list of customers and their room information,
as well as a list of free and reserved rooms.*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class HOTEL
{
    string name;
    string address;
    int number_of_stars;
    int number_of_rooms;

public:
    void set_info(string name, string address, int number_of_stars, int number_of_rooms);
    void print_name();
};

void HOTEL::set_info(string name, string address, int number_of_stars, int number_of_rooms)
{
    this->name = name;
    this->address = address;
    this->number_of_stars = number_of_stars;
    this->number_of_rooms = number_of_rooms;
}

void HOTEL::print_name()
{
    cout << this->name;
}

int main(void)
{

    return 0;
}