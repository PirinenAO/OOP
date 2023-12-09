#ifndef USER_H
#define USER_H
#include "person.h"
#include <string>
using namespace std;

class User : public Person
{
    string username;
    string password;
    char permissions[3];
    void set_permissions(char array[3]);

    friend class Admin;

public:
    User();
    User(string first_name, string surname, string phone_number);
    string get_username();
    string return_permissions();
    bool compare(Person person_to_compare);
};

#endif
