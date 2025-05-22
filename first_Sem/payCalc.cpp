/** 
 * Program: Weekly Pay Calculator
 * Purpose: This program calculates the weekly pay for an employee 
 *          based on the number of hours worked and the hourly pay rate.
 *          It accounts for overtime pay for hours worked beyond 40, where 
 *          overtime is paid at 1.5x the regular rate.
 * Inputs: The user is prompted for the number of hours worked (double) 
 *         and the pay rate (double). Input is validated to ensure 
 *         non-negative hours, at most 80 hours worked, and a pay rate 
 *         of at least $7.25 (US federal minimum wage).
 * Outputs: If valid input is provided, the weekly pay is displayed 
 *          with two decimal places. If input is invalid, appropriate 
 *          error messages are printed.
 */

#include <iostream>
#include <iomanip>  // for setting precision

using namespace std;

/**
 * Function: getInput
 * Purpose: This function prompts the user for the number of hours worked 
 *          and the hourly pay rate. It checks that hours are non-negative, 
 *          hours worked are not more than 80, and that the pay rate is 
 *          at least $7.25. It returns true if input is valid, false otherwise.
 * Inputs: Two double variables passed by reference - hoursWorked and payRate.
 * Outputs: Returns true for valid input, otherwise false. It prints error 
 *          messages for invalid input.
 */
bool getInput(double &hoursWorked, double &payRate) {
    
    // Prompt for user input
    cout << "Enter the number of hours worked and hourly pay rate:\n";
    cin >> hoursWorked >> payRate;

    bool isValid = true;  // Track validity of input
    
    // Validate hours worked
    if (hoursWorked < 0) {
        cout << "Hours worked must be non-negative." << endl;
        isValid = false;
    }
    
    if (hoursWorked > 80) {
        cout << "At most 80 hours may be worked in a week." << endl;
        isValid = false;
    }
    
    // Validate pay rate
    if (payRate < 7.25) {
        cout << "Pay rate must be at least minimum wage." << endl;
        isValid = false;
    }

    return isValid;  // Return validity of input
}

int main() {

    double hoursWorked, payRate;  // Local variables for user input

    // Get valid input from the user
    if (!getInput(hoursWorked, payRate)) {
        return 1;  // Exit the program if input is invalid
    }

    double weeklyPay = 0;  // Variable to store calculated weekly pay

    // Calculate weekly pay, accounting for overtime pay beyond 40 hours
    if (hoursWorked <= 40) {
        weeklyPay = hoursWorked * payRate;
    } else {
        weeklyPay = (40 * payRate) + ((hoursWorked - 40) * payRate * 1.5);  
    }

    // Output the weekly pay, formatted to two decimal places
    cout << fixed << setprecision(2);
    cout << "Week's pay: $" << weeklyPay << endl;

    return 0;  // End of program
}