#include "../include/admin.h"
#include "../include/user.h"

#include <iostream>
#include <string>
using namespace std;

ADMIN::ADMIN(string username, string password)
{
    this->usename = username;
    this->password = password;
}

ADMIN::~ADMIN()
{
    cout << "Admin object is being destroyed" << endl;
}

bool ADMIN::authenticate()
{
    string username;
    cout << "Please login as Admin" << endl;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (username == this->usename && password == this->password)
    {
        return true;
    }
    else
    {
        cout << "Authentication failed" << endl;
        return false;
    }
}

void ADMIN::set_username(USER user, string new_username)
{
    if (authenticate())
    {
        user.username = new_username;
    }
}

void ADMIN::set_password(USER user, string new_password)
{
    if (authenticate())
    {
        user.password = new_password;
    }
}