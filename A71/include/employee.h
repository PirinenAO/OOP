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
    void update();
    string return_string();
};