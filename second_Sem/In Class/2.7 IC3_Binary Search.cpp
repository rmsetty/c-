// if the element is present in the array using binary search

// int list[17] = { 2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95 };
// function prototype is int binarySearch(int array[], int size, int value);

// Number of iterations it takes to find the key. 
// If  not found, number of iterations to search the array.

// Enter the element to search: 66
// It takes 4 iterations to find the key 66
// 66 is at index 11
// Here is a sample run for a key not present in the array:

// Enter the element to search: 9
// After  4 iterations 9 is not found!

#include <iostream>

using namespace std;

int binarySearch(int array[], int size, int value);

int main()
{
    int list[17] = { 2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95 };
    int size = sizeof(list)/sizeof(list[0]);
    
    int searchElement;
    
    cout << "Enter the element to search: ";
    cin >> searchElement;
    
    binarySearch(list, size, searchElement);

    return 0;
    
}

int binarySearch(int array[], int size, int searchElement)
{
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    
    int count = 0;
    int index = -1;
    bool found = false;
    
    while (low <= high)
    {
        count++;
        mid = (high + low)/2;
        
        if(array[mid] == searchElement)
        {
            index = mid;
            cout << "It takes " << count << " iterations to find the key " << searchElement << endl;
            cout << searchElement << " is at index " << index << endl;
            break;
        }
        
        else if(array[mid] > searchElement)
        {
            high = mid - 1;
        }
        
        else
        {
            low = mid + 1;
        }
    }
    
    if(index == -1)
    {
        cout << "After " << count << " iterations, " << searchElement << " is not found." << endl; 
    }
    
    return 0;
}


