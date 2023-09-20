#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void addData(int);

const int maxAmountOfStudents = 3;

struct student
{
    std::string name;
    double activiness;
    bool workDone;
    double examPoints;
    int passed : 1;
    int grade : 5;
};

student students[maxAmountOfStudents];

int main(void)
{
    int i = 0;
    for (i = 0; i < maxAmountOfStudents; i++)
    {
        addData(i);
    }

    return 0;
}

void addData(int id)
{
    std::cout << "Name of the student: ";
    std::cin >> students[id].name;
    std::cout << "Activity in exercise and lectures (0.0 - 1.0): ";
    std::cin >> students[id].activiness;
    std::cout << "Is there course work done? (1 yes, 0 no)";
    std::cin >> students[id].workDone;
    std::cout << "Exam score (percentage): ";
    std::cin >> students[id].examPoints;
}