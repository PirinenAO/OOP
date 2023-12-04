#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class PERSON
{
    string first_name;
    string surname;
    string home_address;

public:
    PERSON();
    void set_info(string first_name, string surname, string home_address);
    bool search(string first_name, string surname);
    string return_person()
    {
        return first_name + " " + surname + " " + home_address;
    }
};

#endif