#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include "customer.h"
#include "room.h"
using namespace std;

class HOTEL
{
    string name;
    string address;
    int number_of_stars;
    int number_of_rooms;
    int number_of_customers;
    ROOM *rooms;
    CUSTOMER *customers;

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
};

#endif