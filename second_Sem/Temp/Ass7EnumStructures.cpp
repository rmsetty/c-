w/*
Pseudocode:
1. Ask the user for the maximum number of accounts.
   - Validate input with a limit of 5 attempts.
2. Create a dynamic array to store account details.
3. Display a menu with options:
   - (1) Enter data for an account
   - (2) Display data for a specific account
   - (3) Display all accounts
   - (4) Quit
4. Based on the user's choice, perform actions:
   - If (1), get account details and validate them before storing.
   - If (2), ask for an account number and display if it exists.
   - If (3), display all accounts if any exist.
   - If (4), free memory and exit.
5. Continue looping until the user chooses to quit or exceeds input attempts.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
using namespace std;

// Structure to store personal details of the account owner
struct Person
{
    string name;   // Account holder's name
    string address; // Account holder's address
};

// Structure to store account details
struct Account
{
    int accountNumber;  // Unique account number
    Person ownerInfo;   // Owner details
    double balance;     // Account balance
};

// Function declarations
void populateAccount(Account accounts[], int& numAccounts, int maxAccounts);
void printAccount(const Account& account);
bool DuplicatedAccount(const Account accounts[], int numAccounts, int accountNumber);

int main()
{
    int maxAccounts;
    int numAccounts = 0;
    int choice;
    int attempts = 0;
    
    // Prompt user for maximum number of accounts
    cout << "Enter max number of accounts: ";
    while(true)
    {
        string temp;
        getline(cin, temp);
        istringstream iss(temp);
        if(!(iss >> maxAccounts) || maxAccounts <= 0 || !iss.eof())
        {
            attempts++;
            if(attempts >= 5)
            {
                cout << "Too many unsuccessful attempts, exiting";
                return 1;
            }
            cout << "Invalid value, please reenter: ";
            continue;
        }
        break;
    }
    
    // Allocate dynamic array for storing accounts
    Account* accounts = new Account[maxAccounts];
    
    while(true)
    {
        // Display menu options
        cout << endl << "Menu:" << endl;
        cout << "1->Enter data for specific account, 2->Display data for specific account" << endl;
        cout << "3->Display data for all accounts  , 4->Quit:" << endl;
        
        attempts = 0;
while(attempts < 5)
{
    string temp;
    getline(cin, temp);
    istringstream iss(temp);
    
    if(iss >> choice && iss.eof() && choice >= 1 && choice <= 4)
    {
        break;  // Valid input, exit loop
    }
    
    attempts++;
    if(attempts >= 5)
    {
        cout << "Too many unsuccessful attempts, exiting";
        delete[] accounts;
        return 1;
    }
    
    cout << "Invalid choice, please reenter: ";
}

    
        switch(choice)
        {
            case 1: 
                populateAccount(accounts, numAccounts, maxAccounts);
                break;
            case 2:
            {
                int accountNumber; 
                bool found = false;
                
                // Prompt user for account number
                cout << "Enter account number: ";
                attempts = 0;
                while(attempts < 5)
                {
                    string temp;
                    getline(cin, temp);
                    istringstream iss(temp);
                    if(!(iss >> accountNumber) || accountNumber <= 0 || !iss.eof())
                    {
                        cout << "Invalid value, please reenter: ";
                        attempts++;
                        if(attempts >= 5)
                        {
                            cout << "Too many unsuccessful attempts, exiting";
                            delete[] accounts;
                            return 1;
                        }
                        continue;
                    }
                    break;
                }
                
                // Search for the account number
                for(int i = 0; i < numAccounts; i++)
                {
                    if(accounts[i].accountNumber == accountNumber)
                    {
                        printAccount(accounts[i]);
                        found = true;
                        cout << endl;
                        break;
                    }
                }
                
                if(!found)
                {
                    cout << "Account not found" << endl;
                }
                break;
                
            }
            case 3:
                // Display all stored accounts
                if(numAccounts == 0)
                {
                    cout << "No accounts to display" << endl;
                }
                else
                {
                    for(int i = 0; i < numAccounts; i++)
                    {
                        printAccount(accounts[i]);
                        cout << endl;
                    }
                }
                break;
            case 4:
                // Free memory and exit
                delete[] accounts;
                return 0;
        }
    }
}

// Function to populate account details
void populateAccount(Account accounts[], int& numAccounts, int maxAccounts)
{
    if(numAccounts >= maxAccounts)
    {
        cout << "Cannot execute, array is full" << endl;
        return;
    }
    
    int accountNum;
    string balanceString;
    double balance;
    string name;
    string address;
    int attempts = 0;
    
    // Get account number and validate it
    cout << "Enter account number: ";
    while(attempts < 5)
    {
        string temp;
        getline(cin, temp);
        istringstream iss(temp);
        if(!(iss >> accountNum) || accountNum <= 0 || !iss.eof())
        {
            attempts++;
            if(attempts >= 5)
            {
                cout << "Too many unsuccessful attempts, exiting";
                exit(1);
            }
            cout << "Invalid value, please reenter: ";
            continue;
        }
        if(DuplicatedAccount(accounts, numAccounts, accountNum))
        {
            cout << "Duplicate account number";
            exit(1);
        }
        break;
    }
    
    // Get balance amount
    // Get balance amount
cout << "Enter balance: ";
attempts = 0;
while (attempts < 5)
{
    getline(cin, balanceString);
    istringstream iss(balanceString);
    if (!(iss >> balance) || !iss.eof())
    {
        attempts++;
        cout << "Invalid value, please reenter: ";
        if (attempts >= 3) break;  // Match expected behavior
    }
    else
    {
        break;
    }
}

    
    // Get owner details
    cout << "Enter owner's name: ";
    getline(cin, name);
    cout << "Enter owner's address: ";
    getline(cin, address);
    
    // Store account details
    accounts[numAccounts++] = {accountNum, {name, address}, balance};
}

// Function to print account details
void printAccount(const Account& account)
{
    cout << "Account #: " << account.accountNumber << endl;
    cout << "Owner's name: " << account.ownerInfo.name << endl;
    cout << "Owner's address: " << account.ownerInfo.address << endl;
    cout << "Balance: "  << account.balance;
}

bool DuplicatedAccount(const Account accounts[], int numAccounts, int accountNumber)
{
    for(int i = 0; i < numAccounts; i++)
    {
        if(accounts[i].accountNumber == accountNumber)
        {
            return true;
        }
    }
    return false;
}
