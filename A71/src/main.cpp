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
        cout << endl;
        cout << "Amount of employees in the database: " << number_of_employees << endl;
        cout << "A: add new employee information" << endl;
        cout << "R: remove employee's information" << endl;
        cout << "U: Update employee's information" << endl;
        cout << "S: search based on employee's ID" << endl;
        cout << "Q: quit" << endl;

        c = getchar();
        c = toupper(c);

        cin.ignore();
        bool found = false;
        if (c == 'A') // ADDING EMPLOYEEE
        {
            number_of_employees++;

            EMPLOYEE *temp = new EMPLOYEE[number_of_employees];

            cout << endl
                 << "Give name: " << endl;
            getline(cin, name);
            cout << "Give ID:" << endl;
            cin >> id;
            cin.ignore();
            cout << "Give job" << endl;
            getline(cin, job);
            cout << "Give salary" << endl;
            cin >> salary;

            temp[0] = EMPLOYEE(name, job, salary, id);

            for (int i = 1; i < number_of_employees; i++)
            {
                temp[i] = employees[i - 1];
            }

            employees = temp;
        }
        else if (c == 'R') // REMOVING EMPLOYEE
        {
            int index = 0;

            cout << endl
                 << "Give ID to be removed" << endl;
            cin >> id;

            for (int i = 0; i < number_of_employees; i++)
            {
                if (employees[i].search(id) != nullptr)
                {
                    found = true;
                    number_of_employees--;
                    EMPLOYEE *temp = new EMPLOYEE[number_of_employees];

                    for (int j = 0; j < number_of_employees + 1; j++)
                    {
                        if (j != i)
                        {
                            temp[index] = employees[j];
                            index++;
                        }
                    }

                    employees = temp;
                }
            }

            if (!found)
            {
                cout << endl
                     << "Employee not found" << endl;
            }
        }
        else if (c == 'S') // SEARCHING EMPLOYEE
        {
            cout << endl
                 << "Give ID to search: " << endl;
            cin >> id;

            for (int i = 0; i < number_of_employees; i++)
            {
                if (employees[i].search(id))
                {
                    cout << endl
                         << employees[i].return_string() << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << endl
                     << "Employee not found" << endl;
            }
        }
        else if (c == 'U') // UPDATING EMPLOYEE
        {
            cout << endl
                 << "Give ID of the user: " << endl;
            cin >> id;

            for (int i = 0; i < number_of_employees; i++)
            {
                if (employees[i].search(id))
                {
                    found = true;

                    cin.ignore();
                    cout << endl
                         << "Give name: " << endl;
                    getline(cin, name);
                    cout << "Give ID:" << endl;
                    cin >> id;
                    cin.ignore();
                    cout << "Give job" << endl;
                    getline(cin, job);
                    cout << "Give salary" << endl;
                    cin >> salary;

                    employees[i].update(name, job, id, salary);
                }
            }

            if (!found)
            {
                cout << endl
                     << "Employee not found" << endl;
            }
        }
        else if (c == 'Q') // QUITTING
        {
            delete[] employees;
            exit(0);
        }

        cin.ignore();
    }
}