#include "../include/user.h"
#include <iostream>
#include <string>
using namespace std;

USER::USER(){};

USER::~USER()
{
    cout << endl
         << "REMOVING USER: " + username << endl;
}

USER::USER(string first_name, string surname, string phone_number, string username, string password)
{
    this->first_name = first_name;
    this->surname = surname;
    this->phone_number = phone_number;
    this->username = username;
    this->password = password;
}

string USER::get_info()
{
    return username + " " + first_name + " " + surname + " " + phone_number;
}

string USER::search(string username)
{
    if (this->username == username)
    {
        this->get_info();
    }
    else
    {
        return "USER NOT FOUND";
    }
}