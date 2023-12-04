#ifndef PROFESSION_H
#define PROFESSION_H
#include "person.h"
#include <string>
using namespace std;

class PROFESSION
{
    string title;
    int years_of_experience;
    int latest_salary;

public:
    PROFESSION();
    int get_latest_salary(string title);
    void set_latest_salary(int salary);
    void set_experience(int years_of_experience);
    int get_experience();
    void set_title(string title);
    string get_title();
};

#endif