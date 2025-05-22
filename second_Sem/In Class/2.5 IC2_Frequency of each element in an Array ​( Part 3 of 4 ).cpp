// Write a function to calculate the number of occurrences of each element in an array of size 
// 100. 
// Assume that the elements are in the range 0 to 30, 30 not included. 
// (Given as practice problem)


#include <iostream>

using namespace std;

int main()
{
    int data[100];
    int count[30] = {0};
    
    for(int i = 0; i < 100; i++)
    {
        data[i] = rand() % 30;
        count[data[i]]++;
    }
    
    for (int j = 0; j < 30; j++)
    {
        cout << j << " appeared " << count[j] << " times." << endl;
    }
    
    return 0;
}