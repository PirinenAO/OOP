#include "../include/person.h"
#include "../include/user.h"
#include "../include/admin.h"
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(void)
{
    char c;

    Admin admin = Admin("Admin", "Admin");

    while (true)
    {
        cout << "A to add new user" << endl;
        cout << "R to remove user" << endl;
        cout << "Q to quit" << endl;

        c = getchar();
        c = toupper(c);

        if (c == 'A')
        {
            cout << "adding user" << endl;
        }
        else if (c == 'R')
        {
            cout << "removing user" << endl;
        }
        else if (c == 'Q')
        {
            cout << "quitting" << endl;
            break;
        }
    }
}
