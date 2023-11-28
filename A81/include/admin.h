#ifndef ADMIN_H
#define ADMIN_H

class ADMIN
{
    string usename;
    string password;

public:
    ADMIN(string username, string password);
    ~ADMIN();
    bool authenticate();
    void set_username(USER user, string new_username);
    void set_password(USER user, string new_password);
};

#endif