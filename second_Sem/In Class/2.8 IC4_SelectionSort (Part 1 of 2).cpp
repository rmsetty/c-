// Sort the elements in array using selection sort 

// void SelectionSort(int [], int numRecords );

// You should get the elements of the array from the user. 
// Size of the array is 10. 
// # elements should not be greater than the size of the array. 

// display the sorted elements.

// How many elements? 15
// The number of elements should be less than 11 and greater than 0
// How many elements? 4
// Enter the elements: 12 45 23 14
// The sorted array is : 12 14 23 45

#include <iostream>

using namespace std;

void SelectionSort(int arr[], int arraySize);

int main()
{
    int arraySize = 0;
    
    while(arraySize <= 0 || arraySize > 10)
    {
        cout << "How many elements? ";
        cin >> arraySize;
        
        if(arraySize <= 0 || arraySize > 10)
        {
            cout << "The number of elements should be less than 11 and greater than 0" << endl;
        }
    }
    
    int arr[arraySize] = {0};
    
    cout << "Enter the elements: ";
    for(int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }
    
    SelectionSort(arr, arraySize);
    
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
    
}

void SelectionSort(int arr[], int arraySize)
{
    int minIndex;
    int temp;
    for(int i = 0; i < arraySize - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < arraySize; j++)
        {
            if(arr[j]< arr[i])
            {
                minIndex = j;
            }
        }
        
        if(minIndex != i)
        {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}