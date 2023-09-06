#include <iostream>
using namespace std;

// declaring functions
void countFirstSeries(void);
void countSecondSeries(void);

// main function
int main(void)
{
    cout << "First 15 numbers of the first series:" << endl;  // printing header text
    countFirstSeries();                                       // calling the first function which counts and prints the first series of numbers
    cout << endl;                                             // new line
    cout << "First 15 numbers of the second series:" << endl; // printing header text
    countSecondSeries();                                      // calling the second function which counts and prints the second series of numbers
}

// function definitions
void countFirstSeries(void)
{
    // variables which are used inside the for loop
    int i;
    int j = 0;

    for (i = 1; i <= 7; i++) // looping 7 times, because we want to print 15 numbers (7x2 prints + 1 print after the loop = 15 prints)
    {
        cout << i << "," << j << ","; // printing i and j variables
        j++;                          // incrementing j for the next loop round
    }

    cout << i << "," << endl; // printing once after the loop for the 15th number of the series
}

void countSecondSeries(void)
{
    // variables which are used inside the loop
    int i;
    int x = 1, y = 1, z = 1; // xyz variables are 1's for the start
    for (i = 0; i < 5; i++)  // looping 5 times, because we want to print 15 numbers (5x3 prints = 15 prints)
    {
        cout << x << "," << y << "," << z << ","; // printing xyz
        // adding variables together for the next loop
        x += y + z;
        y += x + z;
        z += x + y;
        // hello
    }
}