#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include <string>
using namespace std;

class ADMIN
{
    string username;
    string password;

public:
    ADMIN();
    ADMIN(string username, string password);
    ~ADMIN();
    bool authenticate();
    void set_username(USER &user, string new_username);
    void set_password(USER &user, string new_password);
};

#endif