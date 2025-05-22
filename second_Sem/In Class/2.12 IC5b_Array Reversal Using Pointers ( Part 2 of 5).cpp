// Two inputs:
// 1. size
// 2. seed

// Output:
// 1. The original randomly generated array.
// 2. The reversed array

// Write a function to find reverse all array elements using pointers and display the reversed array.


// int* createArray(int size, int seed);
//     Dynamically allocates an array of size integers.
//     Generates random numbers within the range 0 to 19 using the given seed.

// void printArray(int* arr, int size);
//     Prints the elements of the array.

// int* reverseArrayArray(int *arr, int size);
//     Reverse all array elements using pointer arithmetic (without direct indexing).

#include <iostream>

using namespace std;

int* createArray (int size, int seed);
void printArray(int* arr, int size);
int* reverseArrayArray(int *arr, int size);


int main()
{
    int size = 0;
    int seed = 0;
    
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    cout << endl;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    int* arr = createArray(size, seed);
    
    printArray(arr, size);
    
    arr = reverseArrayArray(arr, size);
    
    printArray(arr, size);
    
    delete[] arr;
    arr = nullptr;

    return 0;
    
}

int* createArray(int size, int seed)
{
    int* arr = new int[size];
    srand(seed);
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 20;
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

int* reverseArrayArray(int *arr, int size)
{
    int* left = arr;
    int* right = arr + size - 1;
    int temp;
    
    while(left <= right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
        right--;
    }
    
    return arr;
    
}