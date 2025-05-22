#include <iostream>
#include <iomanip>  // For setw
using namespace std;

int main()
{
    // Declare variables for number of pets and total counts
    int numPuppies;
    int numTarantulas;
    int numSnakes;
    int totalLegs;
    int totalEyes;
    int totalTails;
    
    // Prompt the user to enter the number of puppies
    cout << "Enter the number of puppies:\n";
    cin >> numPuppies;
    
    // Prompt the user to enter the number of tarantulas
    cout << "Enter the number of tarantulas:\n";
    cin >> numTarantulas;
    
    // Prompt the user to enter the number of snakes
    cout << "Enter the number of snakes:\n";
    cin >> numSnakes;
    
    // Calculate total legs, eyes, and tails based on input
    totalLegs = (numPuppies * 4) + (numTarantulas * 8);  // Puppies and tarantulas have legs
    totalEyes = (numPuppies * 2) + (numTarantulas * 8) + (numSnakes * 2);  // All have eyes
    totalTails = (numPuppies * 1) + (numSnakes * 1);  // Only puppies and snakes have tails
    
    // Output results, using setw for alignment in the 18th character position
    cout << "Total legs:"  << setw(7) << totalLegs  << endl;
    cout << "Total eyes:"  << setw(7) << totalEyes  << endl;
    cout << "Total tails:" << setw(6)  << totalTails << endl;
    
    return 0;
}