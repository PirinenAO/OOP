#include <iostream>
using namespace std;

// declaring functions
int askInput(void);
int checkPrimes(int number);

// main function
int main(void)
{
    // declaring variables
    int temp;
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

    // printing the header
    cout << "prime numbers between the given numbers " << number1 << " and " << number2 << " are:" << endl;

    // looping through the numbers between the given numbers
    for (int i = number1 + 1; i < number2; i++)
    {
        if (checkPrimes(i)) // using checkPrimes() function to check if the number is prime number
        {
            cout << i << ",";
        }
    }
}

// defining functions

// asking for a number from user and returning it to the main() function
int askInput(void)
{
    int userInput;
    cout << "Give number: ";
    cin >> userInput;

    return userInput;
}

// checking if the number is prime number
int checkPrimes(int number)
{
    if (number <= 1) // 1 and 0 are not prime numbers
    {
        return 0; // if the number is not prime, function returns 0
    }
    // the loop continues as long as i*i is less than or equal to the given number
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1; // if the number is prime number, function returns 1
}