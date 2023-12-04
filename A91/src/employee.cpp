#include "../include/employee.h"
#include <string>
#include <iostream>
using namespace std;

EMPLOYEE::EMPLOYEE()
{
    set_firm("NOKIA");
};

string EMPLOYEE::firm;

EMPLOYEE::EMPLOYEE(string first_name, string surname, string home_address, string title, int experience, int salary, int id)
{
    set_info(first_name, surname, home_address);
    this->set_experience(experience);
    this->set_title(title);
    this->salary = salary;
    this->set_latest_salary(salary);
    this->id = id;
}

void EMPLOYEE::print()
{
    cout << "-----------------------------" << endl;
    cout << "EMPLOYEE INFORMATION" << endl;
    cout << "-----------------------------" << endl;
    cout << this->return_person() << endl;
    cout << "Firm: " << get_firm() << endl;
    cout << "Title: " << get_title() << endl;
    cout << "ID: " << id << endl;
    cout << "Experience in years: " << get_experience() << endl;
    cout << "Salary: " << salary << endl;
    cout << "Tax rate: " << tax_rate << "%" << endl;
    cout << "Net salary: " << get_net_salary() << endl;
}

void EMPLOYEE::set_firm(string firm_name)
{
    firm = firm_name;
}

string EMPLOYEE::get_firm()
{
    return firm;
}

double EMPLOYEE::get_net_salary()
{
    return salary - (salary * (tax_rate / 100));
}
