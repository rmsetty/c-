/**
 * Program Name: printNumberTriangle.cpp
 * Purpose: This program prompts the user to enter a single decimal digit (0-9)
 * and prints a descending triangular pattern of numbers starting from that digit.
 * The first row of the triangle displays digits from the input down to 0, and 
 * each subsequent row begins with one digit less.
 *
 * Input: A single integer digit from 0 to 9 inclusive.
 * Processing: The program validates the input to ensure it is within range,
 * then generates and prints each row of the triangle using nested loops.
 * Output: A triangular pattern of numbers based on the entered digit.
 */

#include <iostream>
using namespace std;

int main() {
    int startDigit;

    // Prompt the user and validate input
    while (true) {
        cout << "Enter a decimal digit: " << endl;
        cin >> startDigit;

        if (cin.fail() || startDigit < 0 || startDigit > 9) {
            // Clear error state and discard invalid input
            cin.clear();
            cin.ignore(10000, '\n');
            
            // Display error message with invalid input
            cout << "Error, " << startDigit << " is not a single decimal digit." << endl;
        } else {
            break; // Valid input received, exit the loop
        }
    }

    // Generate and display the triangle
    for (int i = startDigit; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            cout << j;
        }
        cout << endl; // Move to the next line for a new row in the triangle
    }

    return 0;
}
