#include "../include/profession.h"
#include <iostream>

PROFESSION::PROFESSION(){};

void PROFESSION::set_latest_salary(int salary)
{
    this->latest_salary = salary;
}

int PROFESSION::get_latest_salary(string title)
{
    if (this->title == title)
    {
        return latest_salary;
    }
    else
    {
        return 0;
    }
}

void PROFESSION::set_experience(int years_of_experience)
{

    this->years_of_experience = years_of_experience;
}

int PROFESSION::get_experience()
{
    return this->years_of_experience;
}

void PROFESSION::set_title(string title)
{
    this->title = title;
}

string PROFESSION::get_title()
{
    return this->title;
}