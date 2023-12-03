#include "../include/user.h"
#include <iostream>
#include <string>
using namespace std;

USER::USER(){};

USER::~USER()
{
    cout << "User " << username << " " << password << " is being destroyed" << endl;
}

USER::USER(string first_name, string surname, string phone_number)
{
    this->first_name = first_name;
    this->surname = surname;
    this->phone_number = phone_number;
}

string USER::get_info()
{
    return username + " " + first_name + " " + surname + " " + phone_number;
}

string USER::search(string username)
{
    if (this->username == username)
    {
        return username + " " + password + " " + first_name + " " + surname + " " + phone_number;
    }

    return " ";
}