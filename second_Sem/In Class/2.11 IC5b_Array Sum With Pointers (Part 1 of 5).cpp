// Two Inputs
// 1. Size of array
// 2. Seed value

// Output:
//     The original randomly generated array.
//     The sum of array elements

// Dynamically allocated array of n integers 
// randomly generated elements in range of 0 to 19 using seed. 
// Write a function to find add all array elements using pointers and display the sum.

// exact names, parameters, and order:

// int* createArray(int size, int seed);
//     Dynamically allocated array of n integers 
//     randomly generated elements in range of 0 to 19 using seed. 


// void printArray(int* arr, int size);
//     Prints the elements of the array.

// int sumArray(int *arr, int size);
//     Sum of all array elements using pointer arithmetic (without direct indexing).

// Pointer arithmetic must be used instead of direct indexing for array traversal and modification.

#include <iostream>

using namespace std;

int* createArray(int size, int seed);
void printArray(int* arr, int size);
int sumArray(int *arr, int size);

int main()
{
    int size = 0;
    int seed = 0;
    
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    cout << endl;
    
    cout << "Enter the seed value: ";
    cin >> seed;
    
        cout << endl;
    
    int* arr = createArray(size, seed);
    
    printArray(arr, size);
    
    cout << "The sum of the array is: " << sumArray(arr, size) << endl;
    
    delete[] arr;
    arr = nullptr;
    return 0;
    
    
}

int* createArray(int size, int seed)
{
    srand(seed);
    int* arr = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 20;
        //or arr[i]
        //brackets dereference a pointer as well, just like an astrik
    }
    
    return arr;
    
}

void printArray(int* arr, int size)
{
   for(int i = 0; i < size; i++)
   {
       cout << *(arr + i) << " ";
   }
   
   cout << endl;
}

int sumArray(int *arr, int size)
{
    int sum = 0;
    int* ptr = arr;
    for(int i = 0; i < size; i++)
    {
        sum += *(ptr + i);
    }
    return sum;
}
