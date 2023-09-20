#include <iostream>
#include <string>
using namespace std;

// const variable
const int names = 5;

// declaring function
string getName(int);

// MAIN FUNCTION
int main(void)
{
    string namelist[5] = {}; // empty list
    int i, j, k;             // variable used in our loops
    string temp;             // temporary variable to hold string

    for (i = 0; i < names; i++) // collecting names
    {
        string userInput = getName(i + 1);
        namelist[i] = userInput;
    }

    for (j = 0; j < names; j++) // bubble sort to put names in ascending order
    {
        for (k = j + 1; k < names; k++)
        {
            if (namelist[j] > namelist[k])
            {
                temp = namelist[k];
                namelist[k] = namelist[j];
                namelist[j] = temp;
            }
        }
    }

    cout << endl
         << "Names sorted in ascending alphabetic order: " << endl; // printing header

    for (i = 0; i < names; i++) // printing the names from the list
    {
        cout << namelist[i] << endl;
    }

    return 0;
}

// DEFINING FUNCTIONS

// function which asks user to input names
string getName(int i)
{
    char userInput[100] = {};
    cout << "give " << i << ". name: ";
    cin >> userInput;
    userInput[0] = toupper(userInput[0]); // turning first letter of the string to upper
    return string(userInput);             // returning string back to main function
}