#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

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

#endif