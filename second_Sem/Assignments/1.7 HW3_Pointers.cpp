// Reads grocery product records from a file
// Store the information in parallel array 
// 1.PLU code (STRING)
// 2. Product Name (STRING)
// 3. Product Sales Type 0 = per unit, 1 = per pound (INT)
// 4. Price per Pound or price per unit (DOUBLE)
// 5. Current Inventory Level (pounds or units).

// (A001 Apples 1 0.90 21)  

// Determine number of records in the file
// Dynamically allocate the necessary parallel arrays
// Populate the arrays with the items from the file.
// One Array for each item (5)

// Print Meny 
//     Loops over displaying a menu for the user to choose from:
//     1 – Checkout
//     2 – Print current inventory
//     3 – Quit

// Checkout
//     User can purchase multiple products in each checkout.
//     The user is asked to enter 
//     1. the PLU code, 
//     2. The quantity (weight or # of units, depending on the sales type) for each product. 
//     input validation (quantity must be > 0) 
//     reenter if the input is invalid.
//     make sure the quantity bought is not more than the inventory level (if pick more, sell max inventory)
    
//     The program keeps up with the total cost ($). 
    
//     If PLU is 0, end of checkout. 
//     Displays the total price
//     Displays the menu again. 
//     inventory level should be automatically updated with each purchase.

// Print current inventory
//     Print inventory
//     Keep it updated with all the purchases made so far.

// Quit
//     Exit the menu loop 
//     Print the updated inventory
//     Print “Exiting\n” and terminates.

// readInventory: 
//     reads from a file 
//     populates parallel arrays. 
//     Arguemnts
//     1. File name
//     2. Number of records
//     3. Pointer to PLU array
//     4. Pointer to price array
//     5. Pointer to product name array
//     6. Pointer to product sales type array
//     7. Pointer to inventory array

//     Return true if file open is successful
//     close file when done


// checkout
//     Arguments
//     • Number of records
//     • Pointer to PLU array
//     • Pointer to price array
//     • Pointer to inventory array
//     Updates the data in the arrays to reflect the user's purchase, 
//     Does input validation on purchased quantity (> 0), 
//     asks the user to reenter as long as the quantity is <= 0. 
//     Prompts the user for more purchases. 
//     Type a PLU of zero when done.
//     Returns the total purchase price.
    
//     Release all the dynamic memory at the end.

// c) Outline of main

//      Get file name
//      Find Numer of records
//      Close file
//      Dynamically allocate the parallel arrays (size = # records)
//      Call readInventory
        // Display menu and get user’s choice. (Ask to reenter if invalid)
// While (user’s choice is not Quit)
//      Call checkout if user chooses “Checkout”
//      Print current inventory if user chooses “Print current inventory”
//     Display menu and get user’s choice. (Ask to reenter if invalid)
// End while
// Print current inventory  
// Print “Exiting\n” and terminate


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool readInventory(string fileName, int size, string* PLU, double* unitPrice, string* name, int* productType, double* quantity);
double checkOut(int size, string* PLU, double* unitPrice, double* quantity);
void printInventory(int size, string* PLU, double* unitPrice, string* name, int* productType, double* quantity);

int main()
{
    string fileName;
    
    cout << "Enter the file name:";
    cin >> fileName;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    int size = 0;
    string temp;
    
    while(getline(inputFile, temp))
    {
        if(!temp.empty())
        {
            size++;
        }
    }

    inputFile.close();
    cout << "There are " << size << " records in the file." << endl;
    
    string* PLU = new string[size];
    string* name = new string[size];
    int* productType = new int[size];
    double* unitPrice = new double[size];
    double* quantity = new double[size];
    
    if (readInventory(fileName, size, PLU, unitPrice, name, productType, quantity))
    {
        printInventory(size, PLU, unitPrice, name, productType, quantity);
        
        // While (user’s choice is not Quit)
        //      Call checkout if user chooses “Checkout”
        //      Print current inventory if user chooses “Print current inventory”
        //     Display menu and get user’s choice. (Ask to reenter if invalid)
        // End while
        // Print current inventory  
        // Print “Exiting\n” and terminate
        
        cout << "1 - Checkout" << endl;
        cout << "2 - Print Current Inventory" << endl;
        cout << "3 - Quit" << endl;
        
        int choice = -1;
        
        while (choice != 3)
        {
            cin >> choice;
            while(choice < 1 || choice > 3)
            {
                cout << "Invalid choice, reenter: ";
                cin >> choice;            
            }
            if(choice == 1)
            {
                
                cout << "Total is: " << checkOut(size, PLU, unitPrice, quantity) << endl;
            }
            
            else
            {
                printInventory(size, PLU, unitPrice, name, productType, quantity);
            }
        }
        
        printInventory(size, PLU, unitPrice, name, productType, quantity);
        
        cout << "Exiting\n" << endl;
    }
    
    else
    {
        cout << "Could not open file" << endl;
        cout << "Exiting\n";        
    }
    
    delete[] PLU;
    delete[] name;
    delete[] productType;
    delete[] unitPrice;
    delete[] quantity;
    
    return 0;
}

    // readInventory: 
//     reads from a file 
//     populates parallel arrays. 
//     Arguemnts
//     1. File name
//     2. Number of records
//     3. Pointer to PLU array
//     4. Pointer to price array
//     5. Pointer to product name array
//     6. Pointer to product sales type array
//     7. Pointer to inventory array

//     Return true if file open is successful
//     close file when done
bool readInventory(string fileName, int size, string* PLU, double* unitPrice, string* name, int* productType, double* quantity)
{
    bool fileOpen = true;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    
    if(inputFile)
    {
        for(int i = 0; i < size; i++)
        {
            inputFile >> PLU[i] >> name[i] >> productType[i] >> unitPrice[i] >> quantity[i];
        }
        
        inputFile.close();
    }
    
    else
    {
        fileOpen = false;
    }
    
    return fileOpen;
}


void printInventory(int size, string* PLU, double* unitPrice, string* name, int* productType, double* quantity)
{
    cout << "Inventory read from file" << endl;
    cout << "------------------------" << endl;
    
    cout << fixed << setprecision(2);
    for (int i = 0; i < size; i++)
    {
        cout << "PLU: " << setw(4) << PLU[i] << ", "
             << setw(18) << left << name[i] << ", "
             << "type: " << productType[i] << ", "
             << "unit price: " << setw(6) << right << unitPrice[i] << ", "
             << "inventory: " << quantity[i] << endl;
    }
}

// checkout
//     Arguments
//     • Number of records
//     • Pointer to PLU array
//     • Pointer to price array
//     • Pointer to inventory array
//     Updates the data in the arrays to reflect the user's purchase, 
//     Does input validation on purchased quantity (> 0), 
//     asks the user to reenter as long as the quantity is <= 0. 
//     Prompts the user for more purchases. 
//     Type a PLU of zero when done.
//     Returns the total purchase price.
double checkOut(int size, string* PLU, double* unitPrice, double* quantity)
{
    string selectedPLU;
    cout << "Enter PLU, 0 if done: ";
    cin >> selectedPLU;
    cout << endl;
    
    double totalPrice = 0.0;
    
    while(selectedPLU != "0")
    {
        
        int foundIndex = -1;
        for(int i = 0; i < size; i++)
        {
            if (PLU[i] == selectedPLU)
            {
                foundIndex = i;
            }
        }
        
        if(foundIndex != -1)
        {
            double selectedQuantity = -1;
            cout << "Enter quantity: ";
            cin >> selectedQuantity;
            
            while (selectedQuantity <= 0)
            {
                cout << "Quantity must be positive, reenter: ";
                cin >> selectedQuantity;
                cout << endl;
            }
            
            if(selectedQuantity > quantity[foundIndex])
            {
                selectedQuantity = quantity[foundIndex];
            }
            
            totalPrice += unitPrice[foundIndex] * selectedQuantity;
            
            quantity[foundIndex] -= selectedQuantity;
            
        }
        
        else
        {
            cout << "PLU not found\n";
        }
        
        cout << "Enter PLU, 0 if done: ";
        cin >> selectedPLU;
        
    }
    
    return totalPrice;
}


