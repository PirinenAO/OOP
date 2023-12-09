#include "../include/person.h"
#include "../include/user.h"
#include "../include/admin.h"
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int amount_of_user = 0;

void addUser(vector<User> &users, Admin admin);
void setPermissions(User &user, Admin admin);
void removePermissions(vector<User> &users, Admin admin);
void searchByNumber(vector<User> &users);
void searchByName(vector<User> &users);
bool comparePhoneNumbers(vector<User> users, User user);

int main(void)
{
    char c;

    Admin admin = Admin("a", "a");
    vector<User> users;

    while (true)
    {
        cout << "---------------------------------------------" << endl;
        cout << "Amount of users in database: " << amount_of_user << endl;
        cout << "A to add new user" << endl;
        cout << "R to remove user" << endl;
        cout << "N to search user by name" << endl;
        cout << "M to search user by phone number" << endl;
        cout << "P to remove permissions" << endl;
        cout << "Q to quit" << endl;

        c = getchar();
        c = toupper(c);

        cin.ignore();

        if (c == 'A')
        {
            addUser(users, admin);
        }
        else if (c == 'R')
        {
            cout << "removing user" << endl;
        }
        else if (c == 'N')
        {
            searchByName(users);
        }
        else if (c == 'M')
        {
            searchByNumber(users);
        }
        else if (c == 'P')
        {
            removePermissions(users, admin);
        }
        else if (c == 'Q')
        {
            for (int i = 0; i < amount_of_user; i++)
            {
                cout << "---------------------------------------------" << endl;
                cout << "USER INFORMATION" << endl;
                cout << "---------------------------------------------" << endl;

                cout << users[i].to_string() << endl;
                cout << "Username: " << users[i].get_username() << endl;
                cout << "Permissions:" << users[i].return_permissions() << endl;
            }
            // break;
        }
    }
}

void addUser(vector<User> &users, Admin admin)
{
    string first_name;
    string surname;
    string phone_number;
    string username;
    string password;
    char permissions[3];
    cout << "---------------------------------------------" << endl;
    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);
    cout << "Phone number: " << endl;
    getline(cin, phone_number);
    User user = User(first_name, surname, phone_number);

    if (comparePhoneNumbers(users, user))
    {
        bool bad_number = true;
        while (bad_number)
        {
            cout << "---------------------------------------------" << endl;
            cout << "Phone number already in the database" << endl;
            cout << "---------------------------------------------" << endl;

            cout << "Give new number: " << endl;
            getline(cin, phone_number);
            user = User(first_name, surname, phone_number);

            if (!comparePhoneNumbers(users, user))
            {
                bad_number = false;
                cout << "---------------------------------------------" << endl;
            }
        }
    }

    setPermissions(user, admin);

    cout << "Username: " << endl;
    getline(cin, username);
    if (admin.set_username(user, username))
    {
        cout << "Password: " << endl;
        getline(cin, password);
        if (admin.set_password(user, password))
        {
            users.push_back(user);
            amount_of_user++;
        }
    }
}

void setPermissions(User &user, Admin admin)
{
    char array[3];
    string input;
    cout << "Give permissions (rwx): " << endl;
    getline(cin, input);

    int length = input.length();

    if (length <= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (input[i] == 'r' || input[i] == 'w' || input[i] == 'x')
            {
                array[i] = input[i];
            }
            else
            {
                array[i] = '-';
            }
        }
        admin.set_permissions(user, array);
    }
    else
    {
        cout << "Bad input! Permissions not set!" << endl;
    }
}

void searchByNumber(vector<User> &users)
{
    bool found = false;
    string phone_number;
    cout << "---------------------------------------------" << endl;
    cout << "Number: " << endl;
    getline(cin, phone_number);

    for (int i = 0; i < amount_of_user; i++)
    {
        if (users[i].search(phone_number))
        {
            cout << "---------------------------------------------" << endl;
            cout << "USER INFORMATION" << endl;
            cout << "---------------------------------------------" << endl;

            cout << users[i].to_string() << endl;
            cout << "Username: " << users[i].get_username() << endl;
            cout << "Permissions:" << users[i].return_permissions() << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No users found" << endl;
    }
}

void searchByName(vector<User> &users)
{
    bool found = false;
    string first_name, surname;
    cout << "---------------------------------------------" << endl;

    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);

    for (int i = 0; i < amount_of_user; i++)
    {
        if (users[i].search(first_name, surname))
        {
            cout << "---------------------------------------------" << endl;
            cout << "USER INFORMATION" << endl;
            cout << "---------------------------------------------" << endl;

            cout << users[i].to_string() << endl;
            cout << "Username: " << users[i].get_username() << endl;
            cout << "Permissions:" << users[i].return_permissions() << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No users found" << endl;
    }
}

void removePermissions(vector<User> &users, Admin admin)
{
    bool found = false;
    string first_name, surname;
    cout << "---------------------------------------------" << endl;

    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);

    for (int i = 0; i < amount_of_user; i++)
    {
        if (users[i].search(first_name, surname) && !found)
        {

            found = true;
        }
    }
}

bool comparePhoneNumbers(vector<User> users, User user)
{
    for (int i = 0; i < amount_of_user; i++)
    {
        if (users[i].compare(user))
        {
            return true;
        }
    }

    return false;
}