#include "../include/admin.h"
#include "../include/user.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
    string username;
    string password;

    int number_of_users = 2;

    USER users[2] = {USER("Pekka", "Virtanen", "04040440"), USER("Ville", "Virtanen", "04040440")};

    ADMIN admin("admin", "admin");

    for (int i = 0; i < number_of_users; i++)
    {
        cout << "Setting up username and password for: " << endl;
        cout << users[i].get_info() << endl;

        cout << endl
             << "Username: " << endl;
        getline(cin, username);
        admin.set_username(users[i], username);

        cout
            << "Password: " << endl;
        getline(cin, password);
        admin.set_password(users[i], password);
    }

    cout << "Accounts created: " << endl;

    for (int i = 0; i < number_of_users; i++)
    {
        cout
            << users[i].get_info() << endl;
    }

    cout << endl
         << "Search for user:" << endl;
    getline(cin, username);
    cout << endl;
    for (int i = 0; i < number_of_users; i++)
    {
        cout << users[i].search(username) << endl;
    }
}