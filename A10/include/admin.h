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
    void set_username();
    void set_password();
    void set_permissions(User user, char permissions[3]);
    void remove_permissions(User user, char permissions[3]);
};

#endif
