#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Constants for gravitational acceleration (in m/sec^2)
    const double GRAVITY_VENUS = 8.87;
    const double GRAVITY_EARTH = 9.807;
    const double GRAVITY_MARS = 3.71;
    const double GRAVITY_JUPITER = 24.78;

    // Variable to hold the mass of the object
    double mass;

    // Prompt user for input
    cout << "Please enter the mass of an object in kilograms: ";
    cin >> mass;

    // Check if the entered mass is valid
    if (mass <= 0) {
        cout << "Error, invalid mass entered.\n";
        cout << "The entered mass must be more than zero.\n";
        return 1; // Exit the program with an error code
    }

    // Calculate weights on different planets
    double weightVenus = mass * GRAVITY_VENUS;
    double weightEarth = mass * GRAVITY_EARTH;
    double weightMars = mass * GRAVITY_MARS;
    double weightJupiter = mass * GRAVITY_JUPITER;

    // Output two blank lines
    cout << "\n\n";

    // Display the table header
    cout << left << setw(10) << "Planet" << "\t" << right << setw(16) << "Weight (N) \n" << endl;

    // Display the weights
    cout << left << setw(10) << "Venus" << "\t" << right << setw(16) << fixed << setprecision(3) << weightVenus;

    // Display message for weight on Earth
    if (weightEarth > 1500) {
        cout << "    The object is heavy.";
    } else if (weightEarth < 25) {
        cout << "    The object is light.";
    }
    cout << endl;

    cout << left << setw(10) << "Earth" << "\t" << right << setw(16) << fixed << setprecision(3) << weightEarth << endl;
    cout << left << setw(10) << "Mars" << "\t" << right << setw(16) << fixed << setprecision(3) << weightMars << endl;
    cout << left << setw(10) << "Jupiter" << "\t" << right << setw(16) << fixed << setprecision(3) << weightJupiter << endl;

    return 0; // Exit the program successfully
}
