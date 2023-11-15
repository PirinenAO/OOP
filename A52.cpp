/*A program in which you use recursion to calculate the following sums:
1⁄2 + 1⁄4 + 1⁄6+...+1⁄2n
-1⁄3 * -2⁄5 * -3⁄7*...*-n⁄(2n+1)*/

#include <iostream>
using namespace std;

double sumFunction(double);
double multiplicationFunction(double);

int main(void)
{
    double n = 3;

    // first sequence
    cout << "first: " << endl;
    double sum1 = sumFunction(n);
    std::cout << sum1 << endl;

    // second sequence
    cout << endl
         << "second:  " << endl;
    double sum2 = multiplicationFunction(n);
    std::cout << sum2;

    return 0;
}

double sumFunction(double n)
{
    if (n == 1)
    {
        return 1 / 2.0;
    }

    return 1.0 / (2 * n) + sumFunction(n - 1);
}

double multiplicationFunction(double n)
{

    if (n == 1)
    {
        return -1 / 3.0;
    }

    return -n / (2 * n + 1) * multiplicationFunction(n - 1);
}
