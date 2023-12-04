#include "../include/person.h"
#include <iostream>

PERSON::PERSON(){};

bool PERSON::search(string first_name, string surname)
{

    if (this->first_name == first_name && this->surname == surname)
    {
        return true;
    }
    else
    {
        cout << "User not found" << endl;
        return false;
    }
}

void PERSON::set_info(string first_name, string surname, string home_address)
{
    this->first_name = first_name;
    this->surname = surname;
    this->home_address = home_address;
}