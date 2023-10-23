#include <iostream>
using namespace std;

double firstSum(double);
double secondSum(double);

int main(void)
{
    double x = 3;
    double y = -3;

    // first sequence
    cout << "sum of numbers: " << endl;
    double sum1 = firstSum(x);
    cout << " is: ";
    std::cout << sum1 << endl;

    // second sequence
    cout << endl
         << "multiplication of numbers: " << endl;
    double sum2 = secondSum(y);
    cout << " is: ";
    std::cout << sum2;

    return 0;
}

double firstSum(double n)
{
    while (n)
    {
        cout << "1/" << 2 * n;
        // if statement for adding plus signs
        if (n != 1) // not adding plus sign after the last number
        {
            cout << " + ";
        }

        // adding the sums together in descending order
        return 1.0 / (2 * n) + firstSum(n - 1);
    }

    return 0;
}

double secondSum(double n)
{
    while (n != 0)
    {
        cout << n << "/" << (2 * n) + 1 << " * ";
        return (n / (2 * n)) * secondSum(n + 1);
    }

    return 0;
}
