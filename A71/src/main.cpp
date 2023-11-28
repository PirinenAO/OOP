#include "../include/employee.h"
#include <iostream>
#include <string>
#include <cstdio>

int main(void)
{
    int number_of_employees = 0;
    string name;
    string job;
    int salary;
    int id;
    char c;

    EMPLOYEE *employees;

    while (true)
    {
        bool found = false;

        cout << endl;
        cout << "Amount of employees in the database: " << number_of_employees << endl;
        cout << "A: Add new employee information" << endl;
        cout << "R: Remove employee's information" << endl;
        cout << "U: Update employee's information" << endl;
        cout << "S: Search based on employee's ID" << endl;
        cout << "Q: Quit" << endl;

        c = getchar();
        c = toupper(c);

        cin.ignore();

        if (c == 'A') // ADDING EMPLOYEEE
        {
            number_of_employees++;
            EMPLOYEE *temp;

            try
            {
                temp = new EMPLOYEE[number_of_employees];
            }
            catch (bad_alloc &xa)
            {
                cout << "memory allocation failed for employee" << endl;
            }

            cout << endl
                 << "Name: " << endl;
            getline(cin, name);
            cout << "ID:" << endl;
            cin >> id;
            cin.ignore();
            cout << "Job:" << endl;
            getline(cin, job);
            cout << "Salary:" << endl;
            cin >> salary;

            temp[number_of_employees - 1] = EMPLOYEE(name, job, salary, id);

            if (number_of_employees != 1)
            {
                for (int i = 0; i < number_of_employees - 1; i++)
                {
                    temp[i] = employees[i];
                }
            }

            employees = temp;
        }
        else if (c == 'R') // REMOVING EMPLOYEE
        {
            cout << endl
                 << "Give ID to be removed" << endl;
            cin >> id;

            for (int i = 0; i < number_of_employees; i++)
            {
                if (employees[i].search(id) != nullptr)
                {
                    found = true;
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
            break;
        }
        cin.ignore();
    }
}