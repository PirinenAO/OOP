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
void printCustomerData(CUSTOMER_INFO *customers, int);

// main function
int main(void)
{
    CUSTOMER_INFO *customers;
    int customer_amount;

    // asking for customer amount as input
    cout << "How many customer you would like to add?" << endl;
    cin >> customer_amount;

    // allocating memory
    try
    {
        customers = new CUSTOMER_INFO[customer_amount];
    }
    catch (bad_alloc &xa)
    {
        cout << "Memory allocation Failed!";
    }

    // calling function to read customer data from input
    readCustomerData(customers, customer_amount);
    // calling function so sort customers in ascending order by purchase amount
    sortCustomerData(customers, customer_amount);
    // calling function to print out customers and their data
    printCustomerData(customers, customer_amount);

    // deleting memory addresses which were reserved for customers
    customers = NULL;
    delete[] customers;

    return 0;
}

// defining functions

// reads name, id and purchase amount from input, and assigns them to customer
void readCustomerData(CUSTOMER_INFO *customers, int customer_amount)
{
    // variables
    int i, id;
    float purchase_amount;

    // reading data from input for all the users
    cout << "-------------------------" << endl;
    for (i = 0; i < customer_amount; i++)
    {
        cin.ignore(); // clearing input buffer to avoid issues
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
        cout << "-------------------------" << endl;
        customers++; // to next memory address/customer
    }
}

// sorts customers in ascending order by the purchase amount, by using bubble sort algorithm
void sortCustomerData(CUSTOMER_INFO *customers, int customer_amount)
{
    // variables
    int i, j;
    CUSTOMER_INFO temp;

    // bubble sort algorithm
    for (i = 0; i < customer_amount; i++)
    {
        for (j = i + 1; j < customer_amount; j++)
        {
            if (customers[i].purchase_amount > customers[j].purchase_amount)
            {
                temp = customers[i];
                customers[i] = customers[j];
                customers[j] = temp;
            }
        }
    }
}

// prints out customers and their data
void printCustomerData(CUSTOMER_INFO *customers, int customer_amount)
{
    int i;
    cout << endl;
    cout << "Customers sorted in ascending order by purchase amount: " << endl;
    cout << "-------------------------" << endl;
    for (i = 0; i < customer_amount; i++)
    {
        cout << "ID: " << customers->id << endl;
        cout << "Name: " << customers->name << endl;
        cout << "Purchase amount: " << customers->purchase_amount << endl;
        cout << "-------------------------" << endl;
        customers++;
    }
}