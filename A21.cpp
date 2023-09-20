#include <iostream>
#include <string>
using namespace std;

std::string getName(int i);

int main(void)
{
    const int names = 5;
    std::string namelist[5] = {};
    int i, j, k;
    std::string temp;

    for (i = 0; i < names; i++)
    {
        std::string userInput = getName(i + 1);
        namelist[i] = userInput;
    }

    for (j = 0; j < names; j++)
    {
        for (k = j + 1; k < names; k++)
        {
            if (namelist[j] > namelist[k])
            {
                temp = namelist[k];
                namelist[k] = namelist[j];
                namelist[j] = temp;
            }
        }
    }

    std::cout << endl
              << "Names sorted in ascending alphabetic order: " << endl;

    for (i = 0; i < names; i++)
    {
        std::cout << namelist[i] << endl;
    }

    return 0;
}

std::string getName(int i)
{
    char userInput[100] = {};
    std::cout << "give " << i << ". name: ";
    std::cin >> userInput;
    userInput[0] = std::toupper(userInput[0]);
    return std::string(userInput);
}