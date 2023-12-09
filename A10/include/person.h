#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person
{
    string first_name;
    string surname;
    string phone_number;

public:
    Person();
    string to_string();

    bool search(string first_name, string surname);
    bool search(string phone_number);
    string return_phone_number();
    void set_info(string first_name, string surname, string phone_number);
};

#endif
