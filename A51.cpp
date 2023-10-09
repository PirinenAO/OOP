/*A program in which you define a struct for customer information.
The fields in the struct should be name (null-terminated string),
id (int) and the amount of purchase (float). The program should first ask
the number of customers and then reserve memory for them and then read the
information of customers and then sort customer information in descending
order based on the customer amount of purchase. Use separate functions
to read, sort and print customer information.*/
#include <iostream>
#include <string>

using namespace std;

// variables
int const NAME_LENGTH = 100;

// declaring stuct
struct CUSTOMER_INFO
{
    char name[NAME_LENGTH];
    int id;
    float purchase_amount;
};

// declaring functions
void readCustomerData(CUSTOMER_INFO *customers, int);
void sortCustomerData(CUSTOMER_INFO *customers, int);
void printCustomerData(CUSTOMER_INFO *customers);

// main function
int main(void)
{
    CUSTOMER_INFO *customers;
    int customer_amount;

    cout << "How many customer you would like to add?" << endl;
    cin >> customer_amount;

    try
    {
        customers = new CUSTOMER_INFO[customer_amount];
    }
    catch (bad_alloc &xa)
    {
        cout << "Memory allocation Failed!";
    }

    readCustomerData(customers, customer_amount);
    sortCustomerData(customers, customer_amount);
}

// defining functions
void readCustomerData(CUSTOMER_INFO *customers, int customer_amount)
{
    int i, id;
    float purchase_amount;
    for (i = 0; i < customer_amount; i++)
    {
        cin.ignore();
        char name[NAME_LENGTH];
        cout << "Customer name: " << endl;
        cin.getline(name, NAME_LENGTH);
        strncpy(customers->name, name, NAME_LENGTH);
        cout << "Give customer ID:" << endl;
        cin >> id;
        customers->id = id;
        cout << "Give purchase amount: " << endl;
        cin >> purchase_amount;
        customers->purchase_amount = purchase_amount;
        customers++;
    }
}

void sortCustomerData(CUSTOMER_INFO *customers, int customer_amount)
{
    int i, j;
    float temp;
    for (i = 0; i < customer_amount; i++)
    {
        for (j = i + 1; j < customer_amount; j++)
        {
            if (customers[i].purchase_amount > customers[j].purchase_amount)
            {
                temp = customers[i].purchase_amount;
                customers[i].purchase_amount = customers[j].purchase_amount;
                customers[j].purchase_amount = temp;
            }
        }
    }

    cout << "biggest: " << customers[0].purchase_amount << endl;
}