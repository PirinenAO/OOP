#ifndef ROOM_H
#define ROOM_H
#include <string>
using namespace std;

class ROOM
{
    int room_number;
    string area;
    string type;
    int price;
    int status;
    string customer;

public:
    void set_info(int room_number, string area, string type, int price);
    void print_info();
    string return_status();
    void change_status(string customer);
    int return_price(int length_of_stay);
    int return_room_number();
};

#endif