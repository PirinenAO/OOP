#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "user.h"
#include <string>
using namespace std;

class Admin : public Person
{
    string username;
    string password;

public:
    Admin();
    Admin(string username, string password);
    bool authenticate();
    bool set_username(User &user, string username);
    bool set_password(User &user, string password);
    void set_permissions(User &user, char array[3]);
    void remove_permissions(User &user, char permissions[3]);
};

#endif
