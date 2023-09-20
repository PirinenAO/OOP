#include <iostream>
using namespace std;

// declaring functions
void countFirstSeries(void);
void countSecondSeries(void);

// main function
int main(void)
{
    cout << "First 15 numbers of the first series:" << endl; // printing header text
    countFirstSeries();                                      // calling the first function which counts and prints the first series of numbers
    cout << endl;
    cout << "First 15 numbers of the second series:" << endl; // printing header text
    countSecondSeries();                                      // calling the second function which counts and prints the second series of numbers
}

// function definitions

// counting the first series of numbers and printing it out
void countFirstSeries(void)
{
    int i;
    int j = 0;

    for (i = 1; i <= 7; i++) // looping 7 times, because we want to print 15 numbers (7x2 prints + 1 print after the loop = 15 prints)
    {
        cout << i << "," << j << ",";
        j++;
    }

    cout << i << "," << endl; // printing once after the loop for the 15th number of the series
}

// counting the second series of numbers and printing it out
// the next number will always be the sum of the last three numbers
// for an example number after numbers 111 will be number 3 (1+1+1)
void countSecondSeries(void)
{
    int i;
    int x = 1, y = 1, z = 1;
    for (i = 0; i < 5; i++) // looping 5 times, because we want to print 15 numbers (5x3 prints = 15 prints)
    {
        cout << x << "," << y << "," << z << ",";
        // adding variables together for the next loop
        x += y + z;
        y += x + z;
        z += x + y;
    }
}