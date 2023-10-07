/*A program in which you define a reference for a pointer variable.*/
#include <iostream>
using namespace std;

// creating int variable
int number = 0;

// creating pointer for the int variable
int *ptr = &number;

// creating a reference for the pointer variable
int &int_reference = *ptr;

int main(void)
{
    // incrementing the int variable by using a reference to its pointer
    while (int_reference != 10)
    {
        cout << ++int_reference << endl;
    }

    return 0;
}
