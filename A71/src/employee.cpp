#include <iostream>
#include <string>
#include "../include/employee.h"
using namespace std;

EMPLOYEE::EMPLOYEE(){};

EMPLOYEE::EMPLOYEE(string name, string job, int salary, int id)
{
    this->name = name;
    this->job = job;
    this->salary = salary;
    this->id = id;
}

string EMPLOYEE::return_string()
{
    return "Name: " + name + " ID: " + to_string(id) + " Job: " + job + " Salary: " + to_string(salary);
}

EMPLOYEE *EMPLOYEE::search(int id)
{
    if (this->id == id)
        return this;

    return nullptr;
}

void EMPLOYEE::update(string name, string job, int id, int salary)
{
    this->name = name;
    this->job = job;
    this->id = id;
    this->salary = salary;
}