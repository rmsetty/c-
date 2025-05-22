/*
    Program: Collatz Conjecture Simulation
    Purpose: This program prompts the user to enter a positive integer and applies the 
             Collatz conjecture process until reaching 1. It keeps track of the number 
             of steps taken to reach 1 and the largest number encountered along the way.

    Input: Positive integer from the user
    Processing: Checks if the integer is positive; if not, outputs an error message.
                If positive, applies the Collatz sequence:
                - If the number is even, divide by 2.
                - If the number is odd, multiply by 3 and add 1.
                Continues this process until the number becomes 1.
    Output: The program displays the initial value, number of steps taken, 
            and the largest number encountered in the sequence.
*/

#include <iostream>
using namespace std;

int main() {
    int x;

    // Prompt user for input
    cout << "Enter a positive integer:" << endl;
    cin >> x;

    // Check for positive integer input
    if (x <= 0) {
        cout << "Not a positive integer." << endl;
        return 1;
    }

    // Initialize variables for steps count and largest number tracking
    int steps = 0;
    int largest = x;
    int current = x;

    cout << "Starting value: " << x << endl;

    // Perform Collatz operations
    while (current != 1) {
        if (current % 2 == 0) {
            current /= 2;
        } else {
            current = current * 3 + 1;
        }

        // Update the largest value encountered
        if (current > largest) {
            largest = current;
        }

        steps++;  // Increment steps counter
    }

    // Output results
    cout << "Steps taken to reach 1: " << steps << endl;
    cout << "Largest number reached: " << largest << endl;

    return 0;
}
