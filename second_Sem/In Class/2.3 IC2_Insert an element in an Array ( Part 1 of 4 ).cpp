#include <iostream>

using namespace std;

int main ()
{
    int sid[] = {1,2,3,4,5};
    int originalSize = sizeof(sid)/sizeof(sid[0]);
    
    int additionalCount = 0;
    
    cout << "How many new IDs to enter: ";
    cin >> additionalCount;
    
    int currentSize = originalSize;
    int newArray[originalSize + additionalCount];
    
    int newID = 0;
    
    bool found = false;
    
    for (int i = 0; i < originalSize; i++)
    {
        newArray[i] = sid[i];
    }
    
    for (int i = 0; i < additionalCount; i++)
    {
        found = false;
        cout << "Enter in the new ID: ";
        cin >> newID;
        
        for (int j = 0; j < currentSize; j++)
        {
            if (newID == newArray[j])
            {
                found = true;
                cout << newID << " found at position " << j << endl;
            }
        }
        
        if (found == false)
        {
            cout << newID << " was not found." << endl;
            
            int position = currentSize - 1;
            while(position >= 0 && newArray[position] > newID)
            {
                newArray[position + 1] = newArray[position];
                position--;
            }
            
            newArray[position + 1] = newID;
            currentSize++;
            cout << newID << " was entered into the array." << endl;
        }
    }
    
    for(int i = 0; i < currentSize; i++)
    {
        cout << newArray[i];    
    }
    
}