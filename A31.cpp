/*A program which reads five decimal numbers from the keyboard and stores them to an array. Use a pointer
to calculate the sum of numbers in the array and print the result to the standard output device.*/
#include <iostream>
using namespace std;

// Constants
const int NUMBERS = 5;

// Variables
double number_list[NUMBERS];
double *list_pointer = number_list; // pointing to the first memory address in array

// Declaring functions
void askNumber();
void countSum();

// Main function
int main(void)
{

    askNumber();
    countSum();
}

// Defining functions

// Asks input from user and adds the decimals to number_list[]
void askNumber(void)
{
    int i;
    double user_input;
    for (i = 0; i < NUMBERS; i++)
    {
        cout << "Give decimal number: ";
        cin >> user_input;
        number_list[i] = user_input;
        cout << endl;
    }
}

// Counts the sum of numbers in list by using pointer
void countSum()
{
    double sum = 0.0;
    int i;
    for (i = 0; i < NUMBERS; i++)
    {
        sum += *list_pointer++; // adding number to sum
    }

    cout << "Sum: " << sum;
}
