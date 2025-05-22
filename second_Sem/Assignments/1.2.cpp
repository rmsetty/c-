// ​You are given an array of n integers. 
// One of the element of array is the sum of the other n-1 integers. 
// Function to find the index of sum

// input size of the array and the elements following it will be the values of the array. For eg 4 61 23 67 78

#include <iostream>

using namespace std;

int main()
{
    int arrSize = 0;
    int sum = 0;
    int foundIndex = -1;
    bool found = false;
    
    cout << "Enter the array size: ";
    cin >> arrSize;
    
    int arr[arrSize];
    
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    for(int i = 0; i < arrSize; i++)
    {
        if(sum - arr[i] == arr[i])
        {
            found = true;
            foundIndex = i;
        }
    }
    
    if(found == true)
    {
        cout << "Index " << foundIndex << " has the sum." << endl;
    }
    
    else
    {
        cout << "No index has the sum" << endl;
    }
    
}