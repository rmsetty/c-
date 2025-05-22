// Sort the elements in array using selection sort algorithm. 

// void SelectionSort(int [], int numRecords );

// Generate an array of size 100. 
// # elements in arr from user. 
//  user input does not exceed 100
 
// random number generator 0 - 49 in arr

// selection sort w/ array.
// Display the sorted elements.

// How many elements? 105
// The number of elements should be less than 101 or greater than 0
// How many elements? -1
// The number of elements should be less than 101 or greater than 0
// How many elements? 6
// Enter a seed value: 20
// The array after populating value is:
//   3 29 23  1 38 45
// The sorted array is :
//   1  3 23 29 38 45

#include <iostream>
#include <iomanip>

using namespace std;


void selectionSort(int arr[], int size);

int main()
{
    int arr[100];
    
    int numElements = 0;
    int seedValue = 0;
    
    
    while (numElements <= 0 || numElements > 100)
    {
        cout << "How many elements? ";
        cin >> numElements;
        
        if(numElements <= 0 || numElements > 100)
        {
            cout << "The number of elements should be less than 101 or greater than 0" << endl;
        }
    }
    
    cout << "Enter in a seed value: ";
    cin >> seedValue;
    srand(seedValue);
    
    cout << "The array after populating the values is: " << endl;
    
    for(int i = 0; i < numElements; i++)
    {
        arr[i] = rand() % 50;
        cout << arr[i] << setw(4);
    }
    
    cout << endl;
    selectionSort(arr, numElements);
    
    cout << "The sorted array is: "<< endl;
    for(int i = 0; i < numElements; i++)
    {
        cout << arr[i] << setw(4);
    }
    
}

void selectionSort(int arr[], int size)
{
    int temp = 0;
    int index = 0;
    
    for(int i = 0; i < size - 1; i++)
    {
        index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[index])
            {
                index = j;
            }
        }
        
        if(index != i)
        {
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
}