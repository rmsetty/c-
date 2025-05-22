#include <iostream>
using namespace std;

/*
 * Purpose: This program calculates how many widgets can be made 
 *          from a given number of components: red rods, green gears, 
 *          and blue bolts. It also calculates the leftover components 
 *          after the widgets are constructed.
 * 
 * Inputs: The program receives the number of red rods, green gears, 
 *         and blue bolts from the user.
 * 
 * Processing: It determines the maximum number of widgets that can 
 *             be constructed based on the available components and 
 *             computes the leftover quantities.
 * 
 * Outputs: The program outputs the number of widgets that can be 
 *          constructed and the leftover quantities of each component.
 */

int main() {

    // Define the number of components required to make one widget
    const int RED_RODS_PER_WIDGET = 3;
    const int GREEN_GEARS_PER_WIDGET = 5;
    const int BLUE_BOLTS_PER_WIDGET = 7;


    // Prompt user for input
    cout << "A widget is made from " 
         << RED_RODS_PER_WIDGET << " red rods, " 
         << GREEN_GEARS_PER_WIDGET << " green gears, and " 
         << BLUE_BOLTS_PER_WIDGET << " blue bolts." 
         << endl;

    int redRods, greenGears, blueBolts;


    // Input the number of components
    cout << "Enter the number of red rods:" << endl;
    cin >> redRods;

    cout << "Enter the number of green gears:" << endl;
    cin >> greenGears;

    cout << "Enter the number of blue bolts:" << endl;
    cin >> blueBolts;

    
    // Check for negative input
    if (redRods < 0 || greenGears < 0 || blueBolts < 0) {
        cout << "Cannot have negative quantities of components." << endl;
        return 1; // Exit with error code
    }

    
    // Calculate the number of widgets that can be made
    int widgets = min(redRods / RED_RODS_PER_WIDGET,
                      min(greenGears / GREEN_GEARS_PER_WIDGET,
                          blueBolts / BLUE_BOLTS_PER_WIDGET));


    // Calculate leftover components
    int leftoverRedRods = redRods - (widgets * RED_RODS_PER_WIDGET);
    int leftoverGreenGears = greenGears - (widgets * GREEN_GEARS_PER_WIDGET);
    int leftoverBlueBolts = blueBolts - (widgets * BLUE_BOLTS_PER_WIDGET);

    
    // Output the results
    cout << "Number of widgets which can be constructed: " 
         << widgets << endl;

    cout << "Leftover red rods: " 
         << leftoverRedRods << endl;

    cout << "Leftover green gears: " 
         << leftoverGreenGears << endl;

    cout << "Leftover blue bolts: " 
         << leftoverBlueBolts << endl;

    
    return 0; // Exit successfully
}
