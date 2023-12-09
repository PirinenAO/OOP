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

    void set_permissions(char permissions[3]);
    void remove_permissions(char permissions[3]);

    friend class Admin;

public:
    User();
    bool compare(Person person_to_compare);
};

#endif
