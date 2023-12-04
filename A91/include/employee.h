#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"
#include "profession.h"
#include <string>
#include <iostream>

class EMPLOYEE : public PERSON, public PROFESSION
{
    int id;
    int salary;
    double tax_rate = 18;
    static string firm;

public:
    EMPLOYEE();
    EMPLOYEE(string first_name, string surname, string home_address, string title, int experience, int salary, int id);
    static void set_firm(string name);
    static string get_firm();
    double get_net_salary();
    void print();
};

#endif