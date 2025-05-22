/** 
 * This program computes the area of regular polygons with 3, 4, 5, and 6 sides 
 * based on the side length entered by the user. 
 * It uses the formula: Area = (n * x^2) / (4 * tan(PI/n)) 
 * where n is the number of sides, and x is the side length.
 *
 * Input: User inputs the side length of the polygon.
 * Processing: The program calculates the area of the polygons.
 * Output: The program displays the areas of polygons with 3, 4, 5, and 6 sides 
 *         in a formatted table.
 */

#include <iostream>   // for input/output operations
#include <iomanip>    // for output formatting
#include <cmath>      // for mathematical calculations like tan and acos

using namespace std;

// Constant for PI initialized using acos(-1)
const double PI = acos(-1);

/**
 * Function to compute the area of a regular polygon.
 * 
 * @param sides: Number of sides of the polygon
 * @param length: Length of each side
 * @return: The computed area of the polygon
 */
double computeArea(int sides, double length) 
{
    // Formula for the area of a regular polygon
    return (sides * length * length) / (4 * tan(PI / sides));
}

int main() 
{
    double sideLength;  // Variable to store the length of the side

    // Prompt the user to enter the side length
    cout << "Enter the side length:\n";
    cin >> sideLength;

    // Check if the entered side length is valid (positive value)
    if (!(sideLength > 0)) 
    {
        cout << "The length must be positive.\n";
        return 1;  // Exit if the length is invalid
    }

    // Print two blank lines before the table output
    cout << "\n\n";

    // Display table headers
    cout << setw(5) << "sides" << setw(12) << "area" << endl;
    cout << endl;

    // Loop through polygons with 3, 4, 5, and 6 sides
    for (int sides = 3; sides <= 6; ++sides) 
    {
        double area = computeArea(sides, sideLength);  // Compute the area
        cout << setw(5) << sides << setw(12) << fixed << setprecision(2) << area << endl;
    }

    return 0;  // Successful execution
}
