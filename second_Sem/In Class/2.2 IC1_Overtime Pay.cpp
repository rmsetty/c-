#include <iostream>

using namespace std;

void calcPay(int numHours, int payRate, int overTimeHours, int& pay)
{
    if(overTimeHours > 10)
    {
        pay = 40 * payRate + (10 * 1.5 * payRate);
    }
    
    else if (overTimeHours > 0)
    {
        pay = 40 * payRate + (overTimeHours * 1.5 * payRate);
    }
    
    else
    {
        pay = numHours * payRate;
    }
    
}


int main () 
{
    int payRate = 0, numHours = 0, overTimeHours = 0, pay = 0;
    
    while (numHours < 1)
    {
        cout << "Input hourly pay rate: " << endl;
        cin >> payRate;
        
        cout << "Input number of hours: " << endl;
        cin >> numHours;
        
        if(numHours < 1)
        {
            cout << "Invalid input. Hours cannot be negative" << endl;
        }
        
    }
    
    if(numHours > 40)
    {
        overTimeHours = numHours - 40;
    }
    
    else
    {
        overTimeHours = 0;
    }
    
    calcPay(numHours, payRate, overTimeHours, pay);
    
    cout << "Your weekly pay: " << pay << endl;
    
    return 0;
    
}