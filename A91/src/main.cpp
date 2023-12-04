#include "../include/profession.h"
#include "../include/person.h"
#include "../include/employee.h"
#include <cstdio>
#include <iostream>
using namespace std;

int number_of_employees = 0;

void addEmployee(EMPLOYEE *&employees);
void removeEmployee(EMPLOYEE *&employees);
void searchEmployee(EMPLOYEE *&employees);
void checkLatestSalary(EMPLOYEE *&employees, string title);

int main(void)
{
    char c;

    EMPLOYEE *employees;

    while (true)
    {
        cout << "-----------------------------" << endl;
        cout << "Amount of users in the system: " << number_of_employees << endl;
        cout << "A: Add new employee information" << endl;
        cout << "R: Remove employee's information" << endl;
        cout << "S: Search based on employee's name" << endl;
        cout << "Q: Quit" << endl;

        c = getchar();
        c = toupper(c);

        if (c == 'A')
        {
            addEmployee(employees);
        }
        else if (c == 'R')
        {
            removeEmployee(employees);
        }
        else if (c == 'S')
        {
            searchEmployee(employees);
        }
        else if (c == 'Q')
        {
            break;
        }
    }
}

void addEmployee(EMPLOYEE *&employees)
{
    number_of_employees++;

    string first_name;
    string surname;
    string home_address;
    string title;
    int experience;
    int salary = 0;
    int id;

    EMPLOYEE *temp;

    try
    {
        temp = new EMPLOYEE[number_of_employees];
    }
    catch (bad_alloc &xa)
    {
        cout << "memory allocation failed for employee" << endl;
    }

    cin.ignore();
    cout << "-----------------------------" << endl;
    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);
    cout << "Home address: " << endl;
    getline(cin, home_address);
    cout << "Job title: " << endl;
    getline(cin, title);
    cout << "Experience in years: " << endl;
    cin >> experience;
    checkLatestSalary(employees, title);
    cout << "Salary: " << endl;
    cin >> salary;
    cout << "ID: " << endl;
    cin >> id;

    temp[number_of_employees - 1] = EMPLOYEE(first_name, surname, home_address, title, experience, salary, id);

    if (number_of_employees != 1)
    {
        for (int i = 0; i < number_of_employees - 1; i++)
        {
            temp[i] = employees[i];
        }
    }

    delete[] employees;
    employees = temp;

    cin.ignore();
}

void checkLatestSalary(EMPLOYEE *&employees, string title)
{
    int latest_salary = 0;

    for (int i = 0; i < number_of_employees - 1; i++)
    {
        if (employees[i].get_latest_salary(title) != 0)
        {
            latest_salary = employees[i].get_latest_salary(title);
        }
    }

    if (latest_salary)
    {
        cout << "(Latest salary for title " << title << " was " << latest_salary << " )" << endl;
    }
}

void searchEmployee(EMPLOYEE *&employees)
{
    cin.ignore();
    string first_name;
    string surname;
    cout << "-----------------------------" << endl;
    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);

    for (int i = 0; i < number_of_employees; i++)
    {
        if (employees[i].search(first_name, surname))
        {
            employees[i].print();
        }
    }
}

void removeEmployee(EMPLOYEE *&employees)
{
    string first_name;
    string surname;
    cin.ignore();
    cout << "First name: " << endl;
    getline(cin, first_name);
    cout << "Surname: " << endl;
    getline(cin, surname);

    for (int i = 0; i < number_of_employees; i++)
    {
        if (employees[i].search(first_name, surname))
        {
            number_of_employees--;

            EMPLOYEE *temp;

            try
            {
                temp = new EMPLOYEE[number_of_employees];
            }
            catch (bad_alloc &xa)
            {
                cout << "memory allocation failed for employee" << endl;
            }

            for (int j = 0; j < number_of_employees; j++)
            {
                if (j >= i)
                {
                    temp[j] = employees[j + 1];
                }
                else
                {
                    temp[j] = employees[j];
                }
            }
            employees = temp;
        }
    }
}
