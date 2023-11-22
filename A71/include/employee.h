#include <iostream>
#include <string>
using namespace std;

class EMPLOYEE
{
    string name;
    string job;
    int id;
    int salary;

public:
    EMPLOYEE();
    EMPLOYEE(string name, string job, int salary, int id);
    EMPLOYEE *search(int id);
    string return_string();
    void update(string name, string job, int id, int salary);
};