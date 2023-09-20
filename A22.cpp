#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void askData(int);
void checkStudent(int);

const int maxAmountOfStudents = 1;

struct student
{
    std::string name;
    double activiness;
    bool workDone;
    double examPoints;
    unsigned int passed : 1;
    unsigned int grade : 5;
};

student students[maxAmountOfStudents];

int main(void)
{
    int i = 0;
    for (i = 0; i < maxAmountOfStudents; i++)
    {
        askData(i);
        std::cout << endl;
    }

    for (i = 0; i < maxAmountOfStudents; i++)
    {
        checkStudent(i);
    }

    return 0;
}

void checkStudent(int id)
{
    // checking if students exam score is 40% or more and if the project work is done
    if (students[id].examPoints >= 40 && students[id].workDone == 1)
    {
        students[id].passed = 1;
        students[id].grade = 4;
        // incrementing grade by one for every 12 points
        if (students[id].examPoints >= 52 && students[id].examPoints < 64)
        {
            students[id].grade += 1;
        }
        else if (students[id].examPoints >= 64 && students[id].examPoints < 76)
        {
            students[id].grade += 2;
        }
        else if (students[id].examPoints >= 76 && students[id].examPoints < 88)
        {
            students[id].grade += 3;
        }
        else if (students[id].examPoints >= 88 && students[id].examPoints < 100)
        {
            students[id].grade += 4;
        }
        else if (students[id].examPoints == 100)
        {
            students[id].grade += 5;
        }
    }
    else
    {
        // if the score is less than 40 or the work is undone, then student won't pass the course
        students[id].passed = 0;
    }

    // checking if the activity is more than 0.5, and incrementing the grade if so
    if (students[id].passed == 1 && students[id].activiness > 0.5)
    {
        students[id].grade += 1;
    }
}

void askData(int id)
{
    std::cout << "Name of the student: ";
    std::cin >> students[id].name;
    std::cout << "Activity in exercise and lectures (0.0 - 1.0): ";
    std::cin >> students[id].activiness;
    std::cout << "Is project work done? (1 yes, 0 no): ";
    std::cin >> students[id].workDone;
    std::cout << "Exam score (percentage): ";
    std::cin >> students[id].examPoints;
}