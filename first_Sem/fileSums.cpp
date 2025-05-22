/**
 * Program: Sum Consecutive Pairs
 * 
 * Purpose: This program reads integers from an input file, calculates the sum
 *          of consecutive pairs, and writes the results to an output file.
 * 
 * Inputs:  - Name of the input file containing integers (one per line)
 *          - Name of the output file to write the sums
 * 
 * Processing:
 *          - Read integers from the input file into a vector
 *          - Calculate the sum of each consecutive pair of integers
 *          - Write each sum to the output file
 * 
 * Outputs: A file containing the sum of each consecutive pair of integers,
 *          with one sum per line
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() 
{
    // Define variables to hold file names
    string inputFileName, outputFileName;

    // Read file names from standard input
    cin >> inputFileName >> outputFileName;

    // Attempt to open the input file
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening files." << endl; // Unified error message
        return 1; // Exit with error code
    }

    // Attempt to open the output file
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening files." << endl; // Unified error message
        inputFile.close();  // Close input file if output fails
        return 1; // Exit with error code
    }
    
    // Vector to store the list of integers
    vector<int> numbers;
    int number;

    // Read integers from the input file and store in the vector
    while (inputFile >> number) 
    {
        numbers.push_back(number);
    }

    // Close the input file after reading is complete
    inputFile.close();

    // Calculate sums of consecutive pairs and write to the output file
    for (size_t i = 0; i < numbers.size() - 1; ++i) 
    {
        // Calculate the sum of consecutive pairs
        int sum = numbers[i] + numbers[i + 1];

        // Write each sum to output file on a new line
        outputFile << sum << endl;
    }

    // Close the output file after writing is complete
    outputFile.close();

    return 0; // Single exit point
}
