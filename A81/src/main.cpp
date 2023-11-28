#include "../include/admin.h"
#include "../include/user.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    int number_of_users = 3;
    USER *users = new USER[number_of_users];
    ADMIN admin("admin", "admin");

    users[0] = USER("Pekka", "Virtanen", "041234567", "PekkaVirt2", "pekka123");
    users[1] = USER("Lauri", "Haavisto", "041234567", "Lauri33", "lauri123");
    users[2] = USER("Susanna", "Lahti", "041234567", "SusLah", "susanna123");

    while (true)
    {
        cout << "U: Set new username" << endl;
        cout << "P: Set new password" << endl;
        cout << "S: Search for user" << endl;
    }

    return 0;
}