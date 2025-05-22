#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> 
using namespace std;

#define SIZE 40 // Define the size of the arrays

// Function prototypes
void printArray(int randArray[]);		// Function to print the data array
void bubbleSort(int* list[]);			// Function to sort the pointer array using bubble sort
void printPointerArray(int* ptrArray[]);	// Function to print the pointer array and the values it's pointing to
void swapIntPtr(int** xptr, int** yptr);	// Function to swap two pointers

int main()
{
	int seed ;
	cout << "Enter seed: ";  // Prompt user for seed input
	cin >> seed;             // Take seed input from user
   srand(seed );            // Set the seed for random number generation

	int dataArray[SIZE] = { 0 };  // Create and initialize dataArray with 0 values
	int* pointerArray[SIZE];      // Create pointerArray to hold pointers to elements of dataArray

	// Populate dataArray with random integers between 0 and 2999
	for (int index = 0; index < SIZE; index++)
	{
		dataArray[index] = rand() % 3000;  // Generate random number between 0 and 2999
	}

	// Display dataArray before sorting
	printf("Before Sorting, values in Data Array: \n");
	printArray(dataArray);  // Call function to print the data array
	printf("\n");

	// Populate pointerArray with addresses of elements in dataArray
	for(int i = 0; i < SIZE; i++)
    {
        pointerArray[i] = &dataArray[i];  // Set pointerArray[i] to point to the address of dataArray[i]
    }

	// Display pointerArray before sorting, showing addresses and values they point to
	printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
	printPointerArray(pointerArray);  // Call function to print the pointer array
	printf("\n");

	// Sort pointerArray using bubble sort, but values in dataArray remain unchanged
	bubbleSort(pointerArray);  // Call function to sort the pointer array

	// Display pointerArray after sorting
	printf("\n");
	printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
	printPointerArray(pointerArray);  // Call function to print the pointer array after sorting
	printf("\n");

	// Display dataArray after sorting (should be unchanged)
	printf("\n");
	printf("After Sorting, values in Data Array: \n");
	printArray(dataArray);  // Call function to print the data array
	printf("\n");

   return 0;  // End of program
}

// Function to print the elements of an array
void printArray(int randArray[])
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << randArray[i] << " ";  // Print array elements with spacing

        if((i+1)%10 == 0)  // If 10 elements are printed, move to the next line
            cout << endl;
    }
}

// Bubble sort function to sort the pointer array based on the values they point to
void bubbleSort(int* list[])
{
    bool swapped;

    // Outer loop for multiple passes
    for(int i = 0; i < SIZE - 1; i++)
    {
        swapped = false;  // Flag to track if any swap occurred

        // Inner loop for comparing adjacent elements
        for(int j = 0; j < SIZE - i - 1; j++)
        {
            // Compare the values the pointers point to (dereferencing the pointers)
            if(*list[j] > *list[j+1])
            {
                // Swap the pointers if the value they point to is in the wrong order
                int* temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;

                swapped = true;  // Mark that a swap happened
            }
        }

        // If no swaps happened, the array is sorted, so we break early
        if(!swapped) break;
    }
}

// Function to print the pointer array, showing both addresses and the values they point to
void printPointerArray(int* ptrArray[])
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << ptrArray[i] << " (" << *ptrArray[i] << ") ";  // Print pointer address and the value it points to

        if((i+1)%10 == 0)  // If 10 elements are printed, move to the next line
           cout << endl;
    }
}

// Function to swap two pointers (not used in this program but provided)
void swapIntPtr(int** xptr, int** yptr)
{
    int* temp = *xptr;
    *xptr = *yptr;
    *yptr = temp;
}
