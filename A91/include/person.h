#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class PERSON
{
    string first_name;
    string surname;
    string home_address;

public:
    PERSON();
    PERSON *search(string first_name, string surname);
};

#endif