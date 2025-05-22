#include <iostream>
#include <iomanip>

using namespace std;

// This program calculates the weight of an object on different planets 
// based on its mass in kilograms. It prompts the user for the mass, 
// computes the weight on Venus, Earth, Mars, and Jupiter, and displays 
// the results in a formatted table. Additionally, it indicates if the 
// object is considered heavy or light based on its weight on Earth.
//
// Inputs:
// - Mass of the object in kilograms
//
// Processing:
// - Calculate weight on each planet using the formula: weight = mass * gravity
//
// Outputs:
// - Display the weight on each planet in a formatted table
// - Indicate if the object is heavy or light based on its Earth weight

int main() {

    // Constants for gravitational acceleration on different planets
    const double GRAVITY_VENUS   = 8.87;   // Gravitational acceleration on Venus
    const double GRAVITY_EARTH   = 9.807;   // Gravitational acceleration on Earth
    const double GRAVITY_MARS     = 3.71;     // Gravitational acceleration on Mars
    const double GRAVITY_JUPITER  = 24.78; // Gravitational acceleration on Jupiter


    // Variable to hold the mass of the object in kilograms
    double mass;


    // Prompt user for input
    cout << "Please enter the mass of an object in kilograms: ";
    cin >> mass;


    // Check if the entered mass is valid (greater than zero)
    if (mass <= 0) {
        cout << "Error, invalid mass entered.\n";
        cout << "The entered mass must be more than zero.\n";
        return 1; // Exit the program with an error code
    }


    // Calculate weights on different planets
    double weightVenus   = mass * GRAVITY_VENUS;   // Weight on Venus
    double weightEarth   = mass * GRAVITY_EARTH;   // Weight on Earth
    double weightMars    = mass * GRAVITY_MARS;     // Weight on Mars
    double weightJupiter = mass * GRAVITY_JUPITER; // Weight on Jupiter


    // Output two blank lines for formatting
    cout << "\n\n";

    
    // Display the table header
    cout << left 
         << setw(10) << "Planet" 
         << "\t " 
         << right 
         << setw(16) << "   Weight (N)\n" 
         << endl;

    
    // Display the weight on Venus
    cout << left 
         << setw(10) << "Venus" 
         << "\t" 
         << right 
         << setw(16) << fixed 
         << setprecision(3) 
         << weightVenus 
         << endl;

    
    // Display weight on Earth and corresponding message
    cout << left 
         << setw(10) << "Earth" 
         << "\t" 
         << right 
         << setw(16) << fixed 
         << setprecision(3) 
         << weightEarth;

    if (weightEarth > 1500) {
        cout << "\tThe object is heavy."; // Message for heavy objects
    } 
    else if (weightEarth < 25) {
        cout << "\tThe object is light."; // Message for light objects
    }

    cout << endl;

    
    // Display weight on Mars
    cout << left 
         << setw(10) << "Mars" 
         << "\t" 
         << right 
         << setw(16) << fixed 
         << setprecision(3) 
         << weightMars 
         << endl;

    
    // Display weight on Jupiter
    cout << left 
         << setw(10) << "Jupiter" 
         << "\t" 
         << right 
         << setw(16) << fixed 
         << setprecision(3) 
         << weightJupiter 
         << endl;


    return 0; // Exit the program successfully
}
