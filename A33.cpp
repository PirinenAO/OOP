/*A program in which you define two null-terminated strings by using two pointer variables of type char.
Using only pointers the program must compare two strings character by character and inform what characters
in the strings are the same and what are different.*/
#include <iostream>
using namespace std;

const char *ptr1 = "ABCDEFGHIJK";
const char *ptr2 = "ADCBFFHJIJK";

int main(void)
{
    int counter;
    while (*ptr1 && *ptr2)
    {
        if (*ptr1 == *ptr2)
        {
            cout << *ptr1 << " and " << *ptr2 << " are the same" << endl;
        }
        else
        {
            cout << *ptr1 << " and " << *ptr2 << " are NOT the same" << endl;
        }

        ptr1++;
        ptr2++;
    }
}