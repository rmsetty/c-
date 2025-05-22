// Remove Duplicates from a Sorted Array using Pointers

// Two Inputs:
// size
// seed

// Outputs
// The original randomly generated array.
// The sorted array.
// The modified array after removing duplicates.

// randomly generated within the range 1 to 10
// Sort it in ascending order using pointers
// Rremove duplicate elements

// int* createArray(int size);
//     Dynamically allocates an array of size integers.
//     Generates random numbers within the range 1 to 10 using the given seed.

// void printArray(int* arr, int size);
//     Prints the elements of the array.

// int* sortValues(int *arr, int size);
//     Sorts the array in ascending order using pointer arithmetic (without direct indexing).

// int removeDuplicates(int *arr, int size);
//     Removes duplicates from a sorted array in-place.
//     Returns the new size of the modified array.

#include <iostream>

using namespace std;

int* createArray(int size, int seed);
void printArray(int* arr, int size);
int* sortValues(int *arr, int size);
int removeDuplicates(int *arr, int size);

int main()
{
    int size = 0;
    int seed = 0;
    
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    int* arr = createArray(size, seed);
    
    printArray(arr, size);
    
    arr = sortValues(arr, size);
    
    int newSize = removeDuplicates(arr, size);
    
    cout << "The array after removing non duplicates is: " << endl;
    printArray(arr, newSize);
    
    delete[] arr;
    arr = nullptr;
}

int* createArray(int size, int seed)
{
    srand(seed);
    int* arr = new int[size];
    for(int* ptr = arr; ptr < arr + size; ptr++)
    {
        *ptr = (rand() % 10) + 1;
    }
    
    return arr;
}

void printArray(int* arr, int size)
{
    for(int* ptr = arr; ptr < arr + size; ptr++)
    {
        cout << *ptr << endl;
    }
}

int* sortValues(int *arr, int size)
{
    int temp = 0;
    for(int* i = arr; i < arr + size - 1; i++)
    {
        for(int* j = i + 1; j < arr + size; j++)
        {
            if(*j < *i)
            {
                temp = *j;
                *j = *i;
                *i = temp;
            }
        }
    }
    
    return arr;
}

int removeDuplicates(int *arr, int size)
{
    int* unique = arr;
    for(int* curr = arr + 1; curr < arr + size; curr++)
    {
        if(*unique != *curr)
        {
            *(++unique) = *curr;
        }
    }
    
    return (unique - arr) + 1;
}