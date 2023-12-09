#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
    string first_name;
    string surname;
    string phone_number;

public:
    Person();
    Person(string first_name, string surname, string phone_number);
    string to_string();
    Person search(string first_name, string surname, string phone_number);
};

#endif
