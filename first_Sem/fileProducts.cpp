/** 
 * This program reads two lists of numbers from a file, calculates 
 * the product of corresponding elements from each list, and then 
 * prints the two lists along with their product.
 * 
 * Input: The program expects a filename as input. The file should contain 
 *        the number of elements followed by two lists of numbers.
 * Output: The program will display the two lists and their product in 
 *         a formatted manner, with each number rounded to two decimal places.
 */

#include <iostream>
#include <fstream>
#include <iomanip>  // For formatting the output            

using namespace std;

/** 
 * Function to read data from a file into an array.
 * 
 * Parameters:
 *   infile - the input file stream.
 *   arr    - the array where data will be stored.
 *   size   - the number of elements to read from the file.
 * 
 * This function reads the specified number of elements from the file 
 * into the provided array.
 */
void readArrayData(ifstream& infile, double arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        infile >> arr[i];
    }
}

/** 
 * Function to print the contents of an array.
 * 
 * Parameters:
 *   label - the label to be printed before the array.
 *   arr   - the array to be printed.
 *   size  - the number of elements in the array.
 * 
 * This function prints the elements of the array in a formatted manner 
 * with two decimal places, aligned to the right.
 */
void printArray(const string& label, const double arr[]) 
{
    cout << label << ":";

    // Set formatting flags just once outside the loop for efficiency
    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; ++i) 
    {
        cout << right << setw(9) << arr[i];
    }

    cout << endl;
}

int main() 
{
    string filename;
    const int MAX_SIZE = 100;  // Maximum number of elements in the list
    double list1[MAX_SIZE], list2[MAX_SIZE], product[MAX_SIZE];
    int size;

    // Prompt user for filename
    cin >> filename;
    ifstream infile(filename);

    // Check if the file was successfully opened
    if (!infile) 
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    infile >> size;  // Read the number of elements in each list

    // If size is invalid (non-positive) or too large, handle the error
    if (size <= 0 || size > MAX_SIZE) 
    {
        cout << "Invalid size or size too large!" << endl;
        return 1;
    }

    // Read the elements into the two lists using the readArrayData function
    readArrayData(infile, list1, size);
    readArrayData(infile, list2, size);

    // Calculate the product of corresponding elements
    for (int i = 0; i < size; ++i) 
    {
        product[i] = list1[i] * list2[i];
    }

    // Print the lists and their product using the printArray function
    printArray(" List 1", list1);
    printArray(" List 2", list2);
    printArray("Product", product);

    return 0;  // Single return statement for main
}
