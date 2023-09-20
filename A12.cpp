#include <iostream>
using namespace std;

// declaring functions
int askInput(void);
int countSumBetween(int num1, int num2);

// main function
int main(void)
{
    // declaring variables
    int temp;
    int sum;
    // number1 and 2 will get their values from askInput() function
    int number1 = askInput();
    int number2 = askInput();

    // making sure that number1 is smaller than number2
    if (number1 > number2)
    {
        // if the number1 is bigger than number2, then their values are swapped
        temp = number1;
        number1 = number2;
        number2 = temp;
    }

    sum = countSumBetween(number1, number2); // sum variable gets its value from countSumBetween() function
    cout << "Sum of numbers between the given numbers " << number1 << " and " << number2 << " is: " << endl
         << sum; // printing out the sum
    return 0;
}

// defining functions

// asking for a number from user and returning it to the main() function
int askInput(void)
{
    int userInput;
    cout << "Give the first number: ";
    cin >> userInput;
    return userInput;
}

// counting sum of the numbers between the given numbers, and returning it to main() function
// for an example if the given numbers are 2 and 6, then it counts the sum of number 3, 4 and 5
int countSumBetween(int num1, int num2)
{
    int i = num1 + 1;
    int sum = 0;

    for (i; i < num2; i++)
    {
        sum += i;
    }

    return sum;
}