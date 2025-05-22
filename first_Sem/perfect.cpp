#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
int sumDivisors(int number);
void classifyNumbers(const string &inputFileName, const string &outputFileName);

int main()
{
    string inputFileName, outputFileName;

    // Read input and output file names
    cin >> inputFileName;
    cin >> outputFileName;

    // Process the input file and classify numbers
    classifyNumbers(inputFileName, outputFileName);

    return 0;
}

/**
 * Computes the sum of all divisors of a given number, excluding the number itself.
 *
 * @param number The positive integer for which to calculate the sum of divisors.
 * @return The sum of divisors, excluding the number itself.
 */
int sumDivisors(int number)
{
    int sum = 0;

    // Iterate over possible divisors from 1 to number / 2
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i; // Add divisor to the sum
        }
    }

    return sum; // Return the computed sum
}

/**
 * Reads numbers from an input file, classifies them as perfect, abundant, or deficient,
 * and writes the classification to an output file.
 *
 * @param inputFileName The name of the input file containing numbers.
 * @param outputFileName The name of the output file where results will be written.
 */
void classifyNumbers(const string &inputFileName, const string &outputFileName)
{
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Check if the input or output file cannot be opened
    if (!inputFile || !outputFile)
    {
        cout << "Error opening files." << endl;
        return;
    }

    int number;

    // Read each number from the input file
    while (inputFile >> number)
    {
        int sum = sumDivisors(number); // Compute the sum of divisors

        // Determine the classification based on the sum of divisors
        if (sum == number)
        {
            outputFile << number << " is perfect." << endl;
        }
        else if (sum > number)
        {
            outputFile << number << " is abundant." << endl;
        }
        else
        {
            outputFile << number << " is deficient." << endl;
        }
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();
}
