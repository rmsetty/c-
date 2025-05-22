#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int* createArray(int size, int seed);
int countOccurrences(int *arr, int size, int element);
void printArray(int* arr, int size);

int main() {
    int size, element, seed;

    // Input validation for zero or negative size arrays
    // cout << "Enter the size of the array (must be positive): ";
    cin >> size;
    while (size <= 0) {
        // cout << "Invalid input. Please enter a positive integer for size: ";
        cin >> size;
    }

    // cout << "Enter the seed value: ";
    cin >> seed;

    // Create the array by calling the function
    int* values = createArray(size, seed);
    
    // Call the function to print the array
    // cout << "The array elements are: " << endl;
    printArray(values, size);
    
    // cout << "Enter the element for which you want to find the count: ";
    cin >> element;
    
    // Call the function to count its occurrences
    int count = countOccurrences(values, size, element);
    
    // Display the result
    cout << "The occurrence of " << element << " in the array is " << count << endl;

    // Deallocate memory
    delete[] values;

    return 0;
}

int* createArray(int size, int seed) {
    // Dynamically create an array to hold the numbers
    int* arr = new int[size];

    // Set the random seed using user input
    srand(seed);
    
    // Populate the array with random numbers between 0 and 49
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 50; // Generate numbers between 0 and 49
    }
    
    return arr;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " "; // Print each element using pointer arithmetic
    }
    cout << endl; // Ensure to end the line after printing the array
}

int countOccurrences(int *arr, int size, int element) {
    int count = 0; // Initialize count
    // Count how many times the element appears in the array
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) == element) {
            count++;
        }
    }
    return count; // Return the count
}
