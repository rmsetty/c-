/** 
 * Program: RGB Inverse Color Calculator
 * 
 * This program prompts the user to enter the RGB components of a color,
 * validates the input, and then calculates and prints the inverse (complementary) color.
 * Each RGB component (Red, Green, and Blue) is an integer between 0 and 255.
 * The inverse is calculated by subtracting each component from 255.
 * 
 * If the input is valid, the program prints the inverse RGB values. 
 * If the input is invalid, it displays an error message.
 * 
 * Inputs: RGB components (three integers in the range 0-255)
 * Outputs: Inverse RGB components, or an error message if input is invalid.
 */

#include <iostream>  // For input/output
#include <iomanip>   // For formatting output

using namespace std;

/**
 * Function: getRGBInput
 * Purpose: Prompts the user to enter RGB components (Red, Green, Blue) and 
 *          validates if the values are within the range 0-255.
 * Inputs: Three integer variables passed by reference to store the input RGB values.
 * Outputs: Returns true if the input is valid (all values between 0 and 255); 
 *          otherwise, returns false.
 */
bool getRGBInput(int &red, int &green, int &blue) 
{
    // Prompt the user for RGB values
    cout << "Enter the RGB components of a color" << endl;
    
    // Input the RGB values
    cin >> red >> green >> blue;

    // Check if all components are in the valid range (0-255)
    if ((red >= 0 && red <= 255) && 
        (green >= 0 && green <= 255) && 
        (blue >= 0 && blue <= 255)) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

/**
 * Function: printInverseColor
 * Purpose: Given valid RGB values, calculates and prints the inverse (complementary) color.
 * Inputs: Three integer values representing the RGB components.
 * Outputs: Displays the inverse color in a formatted manner with proper alignment.
 */
void printInverseColor(int red, int green, int blue) 
{
    // Calculate the inverse (complementary) RGB components
    int inverseRed = 255 - red;
    int inverseGreen = 255 - green;
    int inverseBlue = 255 - blue;

    // Display the inverse RGB values with formatting
    cout << "\nInverse Color" << endl;
    cout << "R: " << setw(3) << inverseRed << endl;
    cout << "G: " << setw(3) << inverseGreen << endl;
    cout << "B: " << setw(3) << inverseBlue << endl;
}

int main() 
{
    int red, green, blue;  // Variables to hold the RGB components

    // Get RGB input from the user
    if (getRGBInput(red, green, blue)) 
    {
        // If input is valid, print the inverse color
        printInverseColor(red, green, blue);
    } 
    else 
    {
        // If input is invalid, display an error message
        cout << "\nInvalid Input" << endl;
    }

    return 0;
}
