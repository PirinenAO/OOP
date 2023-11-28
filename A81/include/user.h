#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class USER
{
    string first_name;
    string surname;
    string phone_number;
    string username;
    string password;

public:
    USER();
    USER(string first_name, string surname, string phone_number, string username, string password);
    string get_info();
    string search(string username);
    ~USER();

    friend class ADMIN;
};

#endif