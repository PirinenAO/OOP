#include "../include/admin.h"

Admin::Admin(){};

Admin::Admin(string username, string password)
{
    this->username = username;
    this->password = password;
}