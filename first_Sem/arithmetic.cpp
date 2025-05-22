/**
 * Program Description: 
 * This program prompts the user to input two integers, computes their squares, 
 * calculates the sum of these squares, and finds the average of the squares. 
 * 
 * Inputs: 
 * The user is prompted to enter two integers. 
 * 
 * Processing: 
 * The program computes the square of each integer, the sum of their squares, 
 * and the average of the squares.
 * 
 * Outputs: 
 * The program outputs the square of the first integer, the square of the second 
 * integer, the sum of the squares, and the average of the squares.
 */

#include <iostream>  // Required for input and output operations

using namespace std;

int main() {

    // Declare variables for user input, squares, sum, and average
    int firstInt;
    int secondInt;
    int square1;
    int square2;
    int sumOfSquares;
    double averageOfSquares;

    // Prompt the user for the first integer
    cout << "Enter the first integer:" << endl;
    cin >> firstInt;

    // Prompt the user for the second integer
    cout << "Enter the second integer:" << endl;
    cin >> secondInt;

    // Compute the square of the first integer
    square1 = firstInt * firstInt;

    // Compute the square of the second integer
    square2 = secondInt * secondInt;

    // Compute the sum of the squares
    sumOfSquares = square1 + square2;

    // Compute the average of the squares
    averageOfSquares = sumOfSquares / 2.0;

    // Output the square of the first integer
    cout << "The square of " << firstInt << " is " << square1 << endl;

    // Output the square of the second integer
    cout << "The square of " << secondInt << " is " << square2 << endl;

    // Output the sum of the squares
    cout << "The sum of squares is " << sumOfSquares << endl;

    // Output the average of the squares
    cout << "The average of squares is " << averageOfSquares << endl;

    return 0;  // Return statement to indicate successful execution
}
