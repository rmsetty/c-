// Input a value
// Assign a pointer to point to the value. 

// If the input is not greater than zero, make the Pointer point to a null value
// print out it's not a positive number

// Multiply the value by 100 and output the final value. 
// Modify the value using the pointer.

// Ex: If the user enters 9, the output should be:
// Values: 900
// If the user enters -9, the output should be:
// -9 is not a positive number

#include <iostream>

using namespace std;

int main()
{
    int value = 0;
    int* ptr = nullptr;
    
    cout << "Provide a value: ";
    cin >> value;
    
    if(value <= 0)
    {
        cout << value << " is not a positive number" << endl;
    }
    
    else
    {
        ptr = &value;
        *ptr *= 100;
        
        cout << "Values: " << *ptr << endl;
    }
    
    return 0;
    
}