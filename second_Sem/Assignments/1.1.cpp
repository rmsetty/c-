// Check whether the given string is a palindrome

// Sample input: level

// Output: The given string is a palindrome.

// Sample input: happy

// Output: The given string is not a palindrome.

#include <iostream>
#include <string>

using namespace std;

bool checkPalidrome(string word);

int main()
{
    string word;
    
    cout << "Enter in the word to check: ";
    cin >> word;
    
    int result = checkPalidrome(word);
    
    if(result == true)
    {
        cout << "The given string is a palindrome" << endl;
    }
    
    else
    {
        cout << "The given string is not a palindrome" << endl;
    }
}

bool checkPalidrome(string word)
{
    int low = 0;
    int high = word.length() - 1;
    bool palindrome = true;
    
    while (low <= high)
    {
        if(word[low] != word[high])
        {
            palindrome = false;
        }
        
        low++;
        high--;
    }
    
    return palindrome;
}


