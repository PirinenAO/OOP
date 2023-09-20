#include <iostream>
#include <string>
using namespace std;

// declaring functions
void askData(int);
void checkStudent(int);
void askName(int);
void askActiveness(int);
void askProject(int);
void askExam(int);
void printStudents();

// amount of students our application will take as input
const int amountOfStudents = 3;

// declaring struct
struct student
{
    string name;
    double activeness;
    bool workDone;
    double examPoints;
    unsigned int passed : 1;
    unsigned int grade : 5;
};

// declaring array of students
student students[amountOfStudents];

// MAIN FUNCTION
int main(void)
{
    int i;
    for (i = 0; i < amountOfStudents; i++)
    {
        askData(i);      // asking for input
        checkStudent(i); // calculating grade and checking if course is passed
        cout << endl;
    }

    printStudents(); // printing out all the names and how did they succeed

    return 0;
}

// DEFINING FUNCTIONS

// calculating grade and checking if the course is passed
void checkStudent(int id)
{
    // checking if students exam score is 40% or more, and is the project work done
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

    // checking if the activeness is more than 0.5, and incrementing the grade if so
    if (students[id].passed == 1 && students[id].activeness > 0.5)
    {
        students[id].grade += 1;
    }
}

// asking for user inputs, by calling functions
void askData(int id)
{
    askName(id);
    askActiveness(id);
    askProject(id);
    askExam(id);
    cin.ignore(); // clears input buffer for the next round
}

// asks name of the student
void askName(int id)
{
    bool nameValid = false;
    while (!nameValid)
    {
        cout << "Name of the student: ";
        getline(cin, students[id].name);

        int badInput = 0;
        for (int i = 0; i < students[id].name.size(); i++)
        {
            if (!isalpha(students[id].name[i]) && !isspace(students[id].name[i]))
            {
                badInput = 1;
            }
        }

        if (badInput == 0)
        {
            nameValid = true;
        }
        else
        {
            cout << "Bad input, please use only alphabets and spaces!" << endl;
        }
    }
}

// asks how active the student has been
void askActiveness(int id)
{
    bool activity = false;
    while (!activity)
    {
        cout << "Activeness for taking part into lectures and exercises (decimal between 0.0 - 1.0): ";
        cin >> students[id].activeness;
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

// asks if the project work is done
void askProject(int id)
{
    bool project = false;
    while (!project)
    {
        string userInput;
        cout << "Is project work done? (Yes or No): ";
        cin >> userInput;

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

// asks for the exam score
void askExam(int id)
{
    bool exam = false;
    while (!exam)
    {
        cout << "Exam score (percentage): ";
        cin >> students[id].examPoints;
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

// prints out all the names and how they succeeded
void printStudents()
{
    int i = 0;
    for (i = 0; i < amountOfStudents; i++)
    {
        if (students[i].passed)
        {
            cout << students[i].name << " has passed the course, with grade: " << students[i].grade << endl;
        }
        else
        {
            cout << students[i].name << " didn't pass the course." << endl;
        }
    }
}
