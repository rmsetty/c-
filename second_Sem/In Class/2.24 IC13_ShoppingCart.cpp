// 3 Files to submit:

// ItemToPurchase.h
// ItemToPurchase.cpp
// main.cpp


// Default constructor
//     Private data members
//         string itemName - Initialized in default constructor to "none"
//         int itemPrice - Initialized in default constructor to 0
//         int itemQuantity - Initialized in default constructor to 0
//     Public class functions (mutators & accessors)
//         SetName() & GetName()
//         SetPrice() & GetPrice()
//         SetQuantity() & GetQuantity()

// Prompt user for two items
// Create two objects of ItemToPurchase class. 
// Call cin.Ignore before second object

////////////////////////////////////////////////////////////////////////////////

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase
{
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
    
    public: 
        ItemToPurchase();
        void setName(string name);
        string getName();
        void setPrice(int price);
        int getPrice();
        void setQuantity(int quantity);
        int getQuantity();
};

#endif // ITEMTOPURCHASE_H

////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase :: ItemToPurchase() : itemName("None"), itemPrice(0), itemQuantity(0){}

void ItemToPurchase :: setName(string name)
{
    itemName = name;
}

string ItemToPurchase :: getName()
{
    return itemName;
}

void ItemToPurchase :: setPrice(int price)
{
    itemPrice = price;
}

int ItemToPurchase :: getPrice()
{
    return itemPrice;
}

void ItemToPurchase :: setQuantity(int quantity)
{
    itemQuantity = quantity;
}

int ItemToPurchase :: getQuantity()
{
    return itemQuantity;    
}

////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

int main()
{
    string itemName1 = "";
    int itemPrice1 = 0;
    int itemQuantity1 = 0;
    
    cout << "Item 1" << endl;
    
    cout << "Enter the item name: ";
    cin >> itemName1;
    
    cin.ignore();
    
    cout << "Enter the item price: ";
    cin >> itemPrice1;
    
    cin.ignore();
    
    cout << "Enter the item quantity: ";
    cin >> itemQuantity1;
    
    ItemToPurchase Item1;
    Item1.setName(itemName1);
    Item1.setPrice(itemPrice1);
    Item1.setQuantity(itemQuantity1);
    
    cout << endl;
    
    string itemName2 = "";
    int itemPrice2 = 0;
    int itemQuantity2 = 0;
    
    cout << "Item 2" << endl;
    
    cout << "Enter the item name: ";
    cin >> itemName2;
    
    cin.ignore();
    
    cout << "Enter the item price: ";
    cin >> itemPrice2;
    
    cin.ignore();
    
    cout << "Enter the item quantity: ";
    cin >> itemQuantity2;
    
    ItemToPurchase Item2;
    Item2.setName(itemName2);
    Item2.setPrice(itemPrice2);
    Item2.setQuantity(itemQuantity2);
    
    cout << endl;
    
    cout << "TOTAL COST: " << endl;
    cout << Item1.getName() << setw(2) << Item1.getQuantity() << setw(2) << "@" 
    << setw(2) << "$" << Item1.getPrice() << setw(2) << "=" << setw(2) << "$"
    << Item1.getPrice() * Item1.getQuantity() << endl; 
    
    cout << Item2.getName() << setw(2) << Item2.getQuantity() << setw(2) << "@" 
    << setw(2) << "$" << Item2.getPrice() << setw(2) << "=" << setw(2) << "$"
    << Item2.getPrice() * Item2.getQuantity() << endl; 
    
    cout << endl;
    
    cout << "Total: "<< ((Item1.getPrice() * Item1.getQuantity()) + (Item2.getPrice() * Item2.getQuantity())) << endl;
    
}