#include "../include/user.h"

User::User(){};

User::User(string first_name, string surname, string phone_number)
{
    this->set_info(first_name, surname, phone_number);
}

string User::get_username()
{
    return this->username;
}

void User::set_permissions(char array[3])
{
    for (int i = 0; i < 3; i++)
    {
        permissions[i] = array[i];
    }
}

string User::return_permissions()
{
    string permissions_to_return(permissions, 3);
    return permissions_to_return;
}

bool User::compare(Person person_to_compare)
{
    if (this->return_phone_number() == person_to_compare.return_phone_number())
    {
        return true;
    }
    else
    {
        return false;
    }
}
