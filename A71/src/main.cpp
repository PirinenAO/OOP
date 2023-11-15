#include "../include/employee.h"
#include <iostream>
#include <string>
#include <cstdio>

int main(void)
{
    int number_of_employees = 0;
    //(string name, string job, int salary, int id);
    string name;
    string job;
    int salary;
    int id;
    char c;

    EMPLOYEE *employees;

    while (true)
    {
        cout << "Amount of employees in the database: " << number_of_employees << endl;
        cout << "A: add new employee information" << endl;
        cout << "R: remove employee's information" << endl;
        cout << "S: search based on employee's ID" << endl;
        cout << "Q: quit" << endl;

        c = getchar();
        c = toupper(c);
        cin.ignore();
        if (c == 'A')
        {
            cout << "Give name: " << endl;
            getline(cin, name);
            cout << "Give ID:" << endl;
            cin >> id;
            cin.ignore();
            cout << "Give job" << endl;
            getline(cin, job);
            cout << "Give salary" << endl;
            cin >> salary;

            employees = new EMPLOYEE[number_of_employees];
            employees[number_of_employees] = EMPLOYEE(name, job, salary, id);

            string print = employees->return_string();

            cout << print << endl;

            number_of_employees++;
        }
        else if (c == 'R')
        {
            cout << "Give ID of the employee you want to remove: " << endl;
            cin >> id;
        }
        else if (c == 'S')
        {
            cout << "Give ID to search: " << endl;
            cin >> id;

            for (int i = 0; i < number_of_employees; i++)
            {

                cout << employees[i].return_string();
            }
        }

        cin.ignore();
    }
}