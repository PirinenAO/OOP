#include "../include/admin.h"
#include "../include/user.h"
#include <iostream>
#include <string>
using namespace std;

ADMIN::ADMIN(){};

ADMIN::ADMIN(string username, string password)
{
    this->username = username;
    this->password = password;
}

ADMIN::~ADMIN()
{
    cout << endl
         << "Admin object is being destroyed" << endl;
}

bool ADMIN::authenticate()
{
    string username;
    cout << endl
         << "Please login as Admin" << endl;
    cout << "Admin username: ";
    getline(cin, username);
    cout << "Admin password: ";
    getline(cin, password);

    if (username == this->username && password == this->password)
    {
        cout << endl
             << "Authenticated succesfully" << endl
             << endl;
        ;
        return true;
    }
    else
    {
        cout << "Authentication failed" << endl
             << endl;
        return false;
    }
}

void ADMIN::set_username(USER &user, string new_username)
{
    if (authenticate())
    {
        user.username = new_username;
    }
}

void ADMIN::set_password(USER &user, string new_password)
{
    if (authenticate())
    {
        user.password = new_password;
    }
}