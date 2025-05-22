#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int originalSize = sizeof(arr)/sizeof(arr[0]);
    
    int del = 0;
    cout << "Enter in the number to delete: ";
    cin >> del;
    
    bool found = false;
    int index = 0;
    
    int currentSize = originalSize;
    int newArr[currentSize - 1];
    
    for(int i = 0; i < originalSize; i++)
    {
        if(arr[i] == del)
        {
            found = true;
            index = i;
        }
    }
    
    if(found == true)
    {
        cout << del << " was found at position " << index << endl;
        int idx = 0;
        for(int i = 0; i < currentSize; i++)
        {
            if(arr[i] != del)
            {
                newArr[idx] = arr[i];
                idx++;
            }
        }
        currentSize--;
        for(int j = 0; j < currentSize; j++)
        {
            cout << newArr[j] << " ";
        }
    }
    
    else
    {
        cout << del << " was not found." << endl;
    }
    
    
}