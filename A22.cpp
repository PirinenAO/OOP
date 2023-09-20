#include <iostream>
#include <string>
#include <conio.h>
#include <ctype.h>
using namespace std;

void askData(int);
void checkStudent(int);
void askName(int);
void askActivity(int);
void askProject(int);
void askExam(int);
void alphabeticOrder(int);

const int maxAmountOfStudents = 1;

struct student
{
    std::string name;
    double activeness;
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
    if (students[id].passed == 1 && students[id].activeness > 0.5)
    {
        students[id].grade += 1;
    }
}

void askData(int id)
{
    askName(id);
    askActivity(id);
    askProject(id);
    askExam(id);
}

void askName(int id)
{
    bool name = false;
    while (!name)
    {
        std::cout << "Name of the student: ";
        std::cin >> students[id].name;
        int badInput = 0;
        for (int i = 0; i < students[id].name.size(); i++) // using .size() to get the length of our name
        {
            if (!isalpha(students[id].name[i]))
            {
                badInput = 1;
            }
        }
        if (badInput == 0)
        {
            name = true;
        }
        else
        {
            cout << "Bad input, please use only alphabets!" << endl;
        }
    }
}

void askActivity(int id)
{
    bool activity = false;
    while (!activity)
    {
        std::cout << "Activity in exercises and lectures (decimal between 0.0 - 1.0): ";
        std::cin >> students[id].activeness;
        if (students[id].activeness < 0.0 || students[id].activeness > 1.0)
        {
            cout << "Bad input, give a decimal number between 0.0 and 1.0" << endl;
        }
        else
        {
            activity = true;
        }
    }
}

void askProject(int id)
{
    bool project = false;
    while (!project)
    {
        std::string userInput;
        std::cout << "Is project work done? (Yes or No): ";
        std::cin >> userInput;

        if (userInput == "yes" || userInput == "YES" || userInput == "Yes")
        {
            students[id].workDone = 1;
            project = true;
        }
        else if (userInput == "no" || userInput == "NO" || userInput == "No")
        {
            students[id].workDone = 0;
            project = true;
        }
        else
        {
            cout << "Bad input! Write yes or no." << endl;
        }
    }
}

void askExam(int id)
{
    bool exam = false;
    while (!exam)
    {
        std::cout << "Exam score (percentage): ";
        std::cin >> students[id].examPoints;
        if (students[id].examPoints < 0 || students[id].examPoints > 100)
        {
            cout << "Bad input, give percentage (0-100%)" << endl;
        }
        else
        {
            exam = true;
        }
    }
}

void alphabeticOrder(int)
{
}
