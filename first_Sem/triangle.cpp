#include <iostream>
#include <cmath> // To use trigonometric functions
#include <iomanip> // For fixed formatting, used in displaying the results

using namespace std;

/*
This program performs computations on a right triangle ABC,
where angle ABC is a right angle. Given the length of segment AB
and the measure of angle BAC in radians, the program calculates
the length of AC, BC, and the measure of angle BCA.
*/

// Function to round a double to a specified number of decimal places
double roundToDecimal(double value, int decimalPlaces) {
    double multiplier = pow(10.0, decimalPlaces);
    return round(value * multiplier) / multiplier;
}

int main() {
    // Declare variables to store input and calculated values
    double ab, angle_bac, ac, bc, angle_bca;
    
    // Input: Length of segment AB and measure of angle BAC
    cout << "Enter the length of segment AB:\n";
    cin >> ab;
    cout << "Enter the measure of angle BAC, in radians:\n";
    cin >> angle_bac;
    
    // Calculate the length of the hypotenuse AC using cosine
    ac = ab / cos(angle_bac);
    
    // Calculate the length of segment BC using sine
    bc = ac * sin(angle_bac);
    
    // Calculate the measure of angle BCA in radians
    angle_bca = M_PI / 2 - angle_bac;  // pi/2 radians is 90 degrees
    
    // Output: Display the computed values rounded to 2 decimal places
    cout << "The length of segment AC is: " << fixed << setprecision(2) << roundToDecimal(ac, 2) << endl;
    cout << "The length of segment BC is: " << fixed << setprecision(2) << roundToDecimal(bc, 2) << endl;
    cout << "The measure of angle BCA, in radians, is: " << fixed << setprecision(2) << roundToDecimal(angle_bca, 2) << endl;

    return 0;
}
