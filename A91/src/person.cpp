#include "../include/person.h"
#include <iostream>

PERSON::PERSON(){};

PERSON *PERSON::search(string first_name, string surname)
{
    if (this->first_name == first_name && this->surname == surname)
    {
        return this;
    }

    return NULL;
}