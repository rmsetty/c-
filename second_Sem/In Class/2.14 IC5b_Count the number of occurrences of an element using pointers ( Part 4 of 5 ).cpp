// Number of occurrences of an element using pointers

// Three Inputs
// 1. Size
// 2. Seed Value
// 3. Integer to check for

// Output:
// The number of times the element has occurred in the array.


// randomly generate array elements within the range 0 to 49 
// Count how times an element has occurred

// int* createArray(int size, int seed);
//     Dynamically allocates an array of size integers.
//     Generates random numbers within the range 0 to 49 using the given seed.

// void printArray(int* arr, int size);
//     Prints the elements of the array.

// int countOccurrences(int *arr, int size);
//     Counts how many times an element has occurred.

#include <iostream>

using namespace std;

int* createArray(int size, int seed);
void printArray(int* arr, int size);
int countOccurrences(int* arr, int size);

int main()
{
    int size = 0;
    int seed = 0;
    
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    int* arr = createArray(size, seed);
    
    cout << endl;
    
    printArray(arr, size);
    
    cout << endl;
    
    int count = countOccurrences(arr, size);
    
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
        *(arr+i) = rand() % 50;
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

int countOccurrences(int* arr, int size)
{
    int element = 0;
    int count = 0;
    cout << "Enter in the element to look for: ";
    cin >> element;
    
    for(int i = 0; i < size; i++)
    {
        if(*(arr+i) == element)
        {
            count++;
        }
    }
    
    cout << "The value " << element << " showed up in the array " << count << " time(s)" << endl;
    
    return count;
}

