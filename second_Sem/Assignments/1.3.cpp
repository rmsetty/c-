// string s 
// rotate it by k characters from the beginning to end. 
// Both s and k are input to the program. 
// Cannot use any other array. 
// Cut k characters from the beginning and paste to the end.

// Input: rotatedontknowto 6

// Output: dontknowtorotate

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    string direction = "right";
    int k = 0;
    
    cout << "Enter in the string: ";
    cin >> s;
    
    // cout << "Enter in the number of characters you'd like to rotate the string: ";
    cin >> k; 
    
    int length = s.length();
    k = k % length;
    
    cout << "Enter the direction you would like to rotate the string: ";
    cin >> direction;
    
    if(direction == "right")
    {
        s = s.substr(k) + s.substr(0, k);    
    }
    
    else
    {
        s = s.substr(length - k) + s.substr(0, length - k);
    }
    
    cout << s << endl;
}






