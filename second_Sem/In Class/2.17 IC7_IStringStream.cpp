// Allows users to order food items from a restaurant menu. 

// Read menu from a file (menu.txt)
// Store the item codes, names, and prices in three arrays.

// Display the menu to the user.

// Input Order String (e.g., "A1 A4 E3 D2 S3").
// Validate each code
// 1. Valid, display item name and price.
// 2. Invalid, Error message + skip it.
// Calculate & display total cost of the valid items


// codes[] → Stores item codes (e.g., "A1", "E3", "S2").
// names[] → Stores item names (e.g., "Bruschetta", "Eggplant_Parmigiana").
// prices[] → Stores item prices (e.g., 5.29, 8.99).

// At most 100 items.
// case-sensitive
// Formatted to 2 decimal places.
// Ignores extra spaces

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("Menu.txt");
    
    if(!inputFile)
    {
        cout << "Can't open file." << endl;
    }
    
    else
    {
        string codes[100];
        string names[100];
        double prices[100];
        
        int count = 0;
        while(inputFile >> codes[count] >> names[count] >> prices[count])
        {
            count++;
        }
        
        cout << "Menu:" << endl;
        
        for(int i = 0; i < count; i++)
        {
            cout << left << setw(6) << codes[i]
             << setw(20) << names[i]
             << "$" << fixed << setprecision(2) << prices[i] << endl;
     }
        
        string order;
        cout << "Enter in your order: " << endl;
cin.ignore();  // before getline
        getline(cin, order);
        string itemCode;
        
        istringstream orderStream(order);
        
        double total = 0;
        int c = -1;
        int i = 0;
        while(orderStream >> itemCode)
        {
            c = -1;
            for(int i = 0; i < count; i++)
            {
                if(codes[i] == itemCode)
                {
                    c = i;
                    i = count + 1;
                }
            }
            
            if(c != -1)
            {
                cout << names[c] << ": $" << fixed << setprecision(2) << prices[c] << endl;
                total += prices[c];
            }
            
            else
            {
                cout << itemCode << " is invalid. Skipping it." << endl;
            }
        }
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
        
    }
    
    return 0;
}