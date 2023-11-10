#include "../include/customer.h"
#include <iostream>
#include <string>
using namespace std;

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