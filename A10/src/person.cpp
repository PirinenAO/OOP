#include "../include/person.h"

Person::Person(){};

void Person::set_info(string first_name, string surname, string phone_number)
{
    this->first_name = first_name;
    this->surname = surname;
    this->phone_number = phone_number;
}

string Person::to_string()
{
    return first_name + " " + surname + " " + phone_number;
}

bool Person::search(string first_name, string surname)
{
    if (this->first_name == first_name && this->surname == surname)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Person::search(string phone_number)
{
    if (this->phone_number == phone_number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Person::return_phone_number()
{
    return this->phone_number;
}
