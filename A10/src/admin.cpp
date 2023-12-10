#include "../include/admin.h"

Admin::Admin(){};

Admin::Admin(string username, string password)
{
    this->username = username;
    this->password = password;
}

bool Admin::set_username(User &user, string username)
{
    if (authenticate())
    {
        user.username = username;
        return true;
    }
    else
    {
        cout << "Authentication failed" << endl;

        return false;
    }
}

bool Admin::set_password(User &user, string password)
{
    if (authenticate())
    {
        user.password = password;
        return true;
    }
    else
    {
        cout << "Authentication failed" << endl;

        return false;
    }
}

bool Admin::authenticate()
{

    string username,
        password;
    cout << "---------------------------------------------" << endl;
    cout << "Admin username: " << endl;
    getline(cin, username);
    cout << "Admin password" << endl;
    getline(cin, password);

    if (this->username == username && this->password == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Admin::set_permissions(User &user, char array[3])
{

    user.set_permissions(array);
}

void Admin::remove_permissions(User &user, char array[3])
{
    user.remove_permissions(array);
}
