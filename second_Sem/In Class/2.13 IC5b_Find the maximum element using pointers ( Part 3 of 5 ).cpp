// find maximum element using pointers

// Two Inputs
// 1. size
// 2. Seed 

// Output:
// The largest element of the array.

// int* createArray(int size, int seed);
//     Dynamically allocates an array of size integers.
//     Generates random numbers within the range 0 to 19 using the given seed.

// void printArray(int* arr, int size);
//     Prints the elements of the array.

// int findMax(int *arr, int size);
//     Finds the largest element in the array.

#include <iostream>

using namespace std;

int* createArray(int size, int seed);
void printArray(int* arr, int size);
int findMax(int *arr, int size);

int main()
{
    int size = 0;
    int seed = 0;
    
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    cout << endl;
    
    int* arr = createArray(size, seed);
    
    printArray(arr, size);
    
    int max = findMax(arr, size);
    
    cout << endl;
    
    cout << "The maximum value is: " << max << endl;

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
        cout << *(arr + i) << endl;
    }
}

int findMax(int* arr, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
    if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    
    return max;
}