#include <iostream>
#include <iomanip> // For fixed formatting, used in displaying the results

// This program calculates tip amounts based on a sales amount entered by the user. 
// It displays the tip amounts for 18%, 20%, and 25%. 
// The user then enters a custom tip amount, and the program displays the sales amount, 
// the entered tip amount, and the total (sales amount + tip amount).

using namespace std;

double saleAmnt, tip18, tip20, tip25, tipAmnt;

int main()
{
    // Prompt the user to enter the sale amount
    cout << "Enter the amount of the sale in $: ";
    cin >> saleAmnt;    
    
    // Calculate the tips
    tip18 = saleAmnt * 0.18;
    tip20 = saleAmnt * 0.20;
    tip25 = saleAmnt * 0.25;

    // Display the different tip percentages
    cout << "18% tip = $" << fixed << setprecision(2) << tip18 << endl;
    cout << "20% tip = $" << fixed << setprecision(2) << tip20 << endl;
    cout << "25% tip = $" << fixed << setprecision(2) << tip25 << endl;

    // Prompt the user to enter the tip amount3
    cout << "\nEnter the amount of the tip in $: ";
    cin >> tipAmnt;
    
    // Display the Sales Amount, Tip Amount, and Total, formatted correctly
    cout << "\nSales Amount: $" << fixed << setprecision(2) << saleAmnt << endl;
    cout << "Tip Amount: $" << fixed << setprecision(2) << tipAmnt << endl;
    cout << "Total: $" << fixed << setprecision(2) << saleAmnt + tipAmnt << endl;

    return 0;
}
