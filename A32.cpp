/*A program which reads a string from the standard input and prints
the content of the string in ascending order. Use pointer(s) in the string handling.*/
#include <iostream>
#include <string>
using namespace std;

// variables
string user_input;

// declaring functions
void sortString();

int main(void)
{
    // asking for input
    cout << "Give input: ";
    getline(cin, user_input);
    // calling function to sort and print the input
    sortString();
}

// defining functions

// function which sorts the content of the string in ascending order
void sortString(void)
{
    int LENGTH = user_input.length(); // variable which holds the length of our string
    char *p1, *p2;
    // bubble sort algorithm
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - 1; j++)
        {
            // declaring pointers
            p1 = &user_input[j];
            p2 = p1 + 1;
            // comparing pointers
            if (*p1 > *p2)
            {
                char temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }

    // printing out the sorted string
    cout << endl
         << "Content of the string in ascending order: " << endl
         << user_input << endl;
}