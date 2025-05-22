#include <iostream>
#include <string>  // Include the string library for handling text

using namespace std;

/*
 * This program reads a line of text input from the user
 * and processes it to find and display:
 * 
 * 1. The first character of the string.
 * 2. The 11th character if it exists.
 * 3. The middle character if the string has an odd length.
 * 
 * Input:
 * A line of text entered by the user.
 * 
 * Processing:
 * The program checks the length of the input string and retrieves 
 * specific characters based on the conditions outlined above.
 * 
 * Output:
 * The program displays the first character, the 11th character,
 * and the middle character, or indicates when these characters do not exist.
 */

int main()
{
    string lineOfText;   // Variable to store the input line of text

    char firstCharacter;  // First character of the string
    char eleventhCharacter;  // 11th character of the string
    char middleCharacter;  // Middle character of the string

    // Prompt the user to enter a line of text
    cout << "Enter a line of text:" << endl;
    
    getline(cin, lineOfText);  // Use getline to read the entire line

    
    // Check and print the first character if it exists
    if (lineOfText.length() > 0) {
        
        firstCharacter = lineOfText.at(0);  // Get the first character
        
        cout << "The first character is: " 
             << firstCharacter << endl;
    } else {
        cout << "No first character" << endl;
    }

    
    // Check and print the 11th character if it exists
    if (lineOfText.length() >= 11) {
        
        eleventhCharacter = lineOfText.at(10);  // Get the 11th character
        
        cout << "The 11th character is: " 
             << eleventhCharacter << endl;
    } else {
        cout << "No 11th character" << endl;
    }

    
    // Check and print the middle character if the string has an odd length
    int length = lineOfText.length();  // Store the length of the string

    if (length > 0) {
        
        if (length % 2 != 0) {
            middleCharacter = lineOfText.at(length / 2);  // Get the middle character
            
            cout << "The middle character is: " 
                 << middleCharacter << endl;
        } else {
            cout << "No middle character" << endl;  // Even length, no single middle character
        }
    } else {
        cout << "No middle character" << endl;  // Handle empty input case
    }

    return 0;  // Return 0 to indicate successful completion
}
