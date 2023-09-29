#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// const variable
const int NAMES = 5;
const int LEN = 50;

// declaring function
void getName(char[], int);

// MAIN FUNCTION
int main(void)
{
    char namelist[NAMES][LEN] = {}; // empty list
    int i, j, k;                    // variables used in our loops
    char temp[LEN];                 // temporary variable to hold string

    for (i = 0; i < NAMES; i++) // collecting names
    {
        getName(namelist[i], LEN);
    }

    for (j = 0; j < NAMES; j++) // bubble sort to put names in ascending order
    {
        for (k = j + 1; k < NAMES; k++)
        {
            if (strcmp(namelist[j], namelist[k]) > 0)
            {
                strncpy(temp, namelist[k], LEN);
                strncpy(namelist[k], namelist[j], LEN);
                strncpy(namelist[j], temp, LEN);
            }
        }
    }

    cout << endl
         << "Names sorted in ascending alphabetic order: " << endl; // printing header

    for (i = 0; i < NAMES; i++) // printing the names from the list
    {
        cout << namelist[i] << endl;
    }

    return 0;
}

// DEFINING FUNCTIONS

void getName(char name[], int length)
{
    cout << "give name: ";
    cin.getline(name, length);
}
