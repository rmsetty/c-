/*
Pseudocode for Inventory Management Program:
1. Ask user for input file name
2. Count number of records in file
3. Create dynamic array of Product objects
4. Load product data from file into array
5. Display initial inventory
6. Enter menu loop:
   a. Show menu options
   b. If option 1: Add to inventory
      i. Ask for PLU and amount
      ii. Update inventory if PLU found
      iii. Record transaction
   c. If option 2: Subtract from inventory
      i. Ask for PLU and amount
      ii. Update inventory if PLU found and sufficient stock
      iii. Record transaction
   d. If option 3: Print all products
   e. If option 4: Exit program and show transaction history
7. Clean up memory and exit
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Product.h"

using namespace std;

// Function to print the product array
// Parameters: products - array of Product objects, size - number of products in array
void printProducts(Product* products, int size) {
    cout << "Current inventory" << endl;
    cout << "-----------------" << endl;
    
    // Loop through each product and display its information
    for (int i = 0; i < size; i++) {
        cout << "PLU: " << products[i].getPLU() << ", " 
             << left << setw(17) << products[i].getName() << right 
             << ", type: " << products[i].getType() 
             << ", unit price: " << setw(5) << products[i].getPrice() 
             << ", inventory: " << products[i].getInventory() << endl;
    }
}

// Structure to track transaction history
// Stores transaction number, PLU code, transaction type, and amount
struct Transaction {
    int transactionNum;    // Sequential transaction identifier
    string PLU;            // Product lookup code
    string type;           // Type of transaction (add/subtract)
    int amount;            // Quantity involved in transaction
};

int main() {
    string filename;       // To store input filename
    ifstream inputFile;    // File stream for reading data
    
    // Prompt for filename
    cout << "Enter the file name: ";
    cin >> filename;
    
    // First open the file to count records
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;  // Exit with error code
    }
    
    // Count the number of records by counting lines in file
    int numRecords = 0;
    string line;
    while (getline(inputFile, line)) {
        numRecords++;
    }
    
    cout << "There are " << numRecords << " records in the file" << endl << endl;
    
    // Close and reopen the file to read from beginning
    inputFile.close();
    inputFile.open(filename);
    
    // Dynamically allocate array of Product objects based on count
    Product* products = new Product[numRecords];
    
    // Read from the file and populate the array
    string plu, name;      // Product identifiers
    int type, inventory;   // Product type and quantity
    double price;          // Product price
    
    // Loop through each record in file
    for (int i = 0; i < numRecords; i++) {
        inputFile >> plu >> name >> type >> price >> inventory;
        products[i].setProductAttributes(plu, name, type, price, inventory);
    }
    
    // Print the product array after loading
    cout << "Content of object array" << endl;
    cout << "-----------------------" << endl;
    
    // Display each product's information
    for (int i = 0; i < numRecords; i++) {
        cout << "PLU: " << products[i].getPLU() << ", " 
             << left << setw(17) << products[i].getName() << right 
             << ", type: " << products[i].getType() 
             << ", unit price: " << setw(5) << products[i].getPrice() 
             << ", inventory: " << products[i].getInventory() << endl;
    }
    
    // Transaction history for extra credit
    Transaction transactions[100]; // Array to store up to 100 transactions
    int transactionCount = 0;     // Counter for number of transactions
    
    // Menu loop - continues until user selects exit (4)
    int choice = 0;
    while (choice != 4) {
        // Display menu options
        cout << endl << "Menu" << endl;
        cout << "----" << endl;
        cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
        cout << "3->Print info for all products, 4->Exit" << endl;
        
        cin >> choice;
        
        if (choice == 1) {
            // Option 1: Add to inventory
            string inputPLU;  // To store user-entered PLU
            int amount;       // Amount to add
            
            cout << "Enter the PLU: ";
            cin >> inputPLU;
            
            // Find product with matching PLU
            bool found = false;
            for (int i = 0; i < numRecords; i++) {
                if (products[i].getPLU() == inputPLU) {
                    found = true;
                    
                    cout << "Enter amount to add: ";
                    cin >> amount;
                    
                    // Validate amount is positive
                    if (amount <= 0) {
                        cout << "Amount must be > 0" << endl;
                    } else {
                        // Update inventory by adding specified amount
                        products[i].setInventory(products[i].getInventory() + amount);
                        
                        // Record transaction for extra credit
                        transactions[transactionCount].transactionNum = transactionCount + 1;
                        transactions[transactionCount].PLU = inputPLU;
                        transactions[transactionCount].type = "Add to inventory";
                        transactions[transactionCount].amount = amount;
                        transactionCount++;
                    }
                    break;  // Exit loop once PLU is found
                }
            }
            
            // Display error if PLU wasn't found
            if (!found) {
                cout << "PLU not found" << endl;
            }
        } else if (choice == 2) {
            // Option 2: Subtract from inventory
            string inputPLU;  // To store user-entered PLU
            int amount;       // Amount to subtract
            
            cout << "Enter the PLU: ";
            cin >> inputPLU;
            
            // Find product with matching PLU
            bool found = false;
            for (int i = 0; i < numRecords; i++) {
                if (products[i].getPLU() == inputPLU) {
                    found = true;
                    
                    cout << "Enter amount to subtract: ";
                    cin >> amount;
                    
                    // Validate amount is positive
                    if (amount <= 0) {
                        cout << "Amount must be > 0" << endl;
                    } else {
                        // Determine actual amount to subtract (can't go below 0)
                        int actualAmount = min(amount, products[i].getInventory());
                        
                        // Update inventory by subtracting valid amount
                        products[i].setInventory(products[i].getInventory() - actualAmount);
                        
                        // Record transaction for extra credit
                        transactions[transactionCount].transactionNum = transactionCount + 1;
                        transactions[transactionCount].PLU = inputPLU;
                        transactions[transactionCount].type = "Subtract from inventory";
                        transactions[transactionCount].amount = actualAmount;
                        transactionCount++;
                    }
                    break;  // Exit loop once PLU is found
                }
            }
            
            // Display error if PLU wasn't found
            if (!found) {
                cout << "PLU not found" << endl;
            }
        } else if (choice == 3) {
            // Option 3: Print all products using the printProducts function
            printProducts(products, numRecords);
        } else if (choice == 4) {
            // Option 4: Exit, but first print transaction history (extra credit)
            cout << endl << "History of transactions" << endl;
            cout << "-----------------------" << endl;
            
            // Determine how many transactions to print (up to 5 most recent)
            int startIndex = max(0, transactionCount - 5);
            
            // Print from most recent to least recent (reverse order)
            for (int i = transactionCount - 1; i >= startIndex; i--) {
                cout << "Transaction #: " << transactions[i].transactionNum 
                     << ", PLU: " << transactions[i].PLU 
                     << ", type: " << transactions[i].type 
                     << ", amount: " << transactions[i].amount << endl;
            }
        }
    }
    
    // Clean up dynamic memory to prevent memory leaks
    delete[] products;
    
    return 0;  // Program completed successfully
}