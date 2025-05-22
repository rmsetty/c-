/**
 * Program to demonstrate reversing and rotating an array.
 * 
 * Purpose:
 * - The program contains functions to reverse a portion of an array and to rotate
 *   an entire array forward by a given number of steps.
 * 
 * Inputs:
 * - An integer array to manipulate.
 * - For the reverse function, a starting index and a count of elements to reverse.
 * - For the rotate function, the total number of elements in the array and the 
 *   number of steps to rotate the array.
 * 
 * Outputs:
 * - The modified array is printed after each operation (reverse and rotate).
 */

#include <iostream>
#include <utility> // For std::swap

using namespace std;

/**
 * Reverses a portion of the given array starting from the specified index.
 * 
 * Purpose:
 * - This function reverses a part of the array starting from the given index for 
 *   a specified count of elements.
 * 
 * Inputs:
 * - arr: The array to modify.
 * - index: The starting index of the block to reverse.
 * - count: The number of elements to reverse.
 * 
 * Outputs:
 * - The array is modified in place, with the specified portion reversed.
 */
void reverse(int arr[], int index, int count) 
{
    int left = index;
    int right = index + count - 1;

    while (left < right) 
    {
        // Swap the elements at the left and right positions
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

/**
 * Rotates the entire array forward by a given number of steps.
 * 
 * Purpose:
 * - This function rotates the array forward by a specified number of steps.
 * 
 * Inputs:
 * - arr: The array to rotate.
 * - n: The total number of elements in the array.
 * - steps: The number of positions to rotate the array elements forward.
 * 
 * Outputs:
 * - The array is modified in place, with the elements shifted forward.
 */
void rotate(int arr[], int n, int steps) 
{
    // Ensure steps is within bounds
    steps = steps % n;

    // Step 1: Reverse the entire array
    reverse(arr, 0, n);

    // Step 2: Reverse the first 'steps' elements
    reverse(arr, 0, steps);

    // Step 3: Reverse the remaining elements
    reverse(arr, steps, n - steps);
}

/**
 * Main function that tests the reverse and rotate operations on arrays.
 * 
 * Purpose:
 * - Initializes arrays and demonstrates the reverse and rotate functions.
 * - Prints the array before and after performing the reverse and rotate operations.
 * 
 * Outputs:
 * - The array is printed after each operation: reverse and rotate.
 */
int main() 
{
    // Test reverse function
    int arr1[] = {0, 1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array: ";
    for (int i = 0; i < size1; i++) 
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Reverse elements starting at index 2, 3 elements
    reverse(arr1, 2, 3);

    cout << "Array after reversing block starting at index 2, 3 elements: ";
    for (int i = 0; i < size1; i++) 
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test rotate function
    int arr2[] = {0, 1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original array: ";
    for (int i = 0; i < size2; i++) 
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Rotate array by 2 steps
    rotate(arr2, size2, 2);

    cout << "Array after rotating by 2 steps: ";
    for (int i = 0; i < size2; i++) 
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Rotate array by 4 steps (testing with different number of steps)
    rotate(arr2, size2, 4);

    cout << "Array after rotating by 4 steps: ";
    for (int i = 0; i < size2; i++) 
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
