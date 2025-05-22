#include <iostream>
#include <string>  // Include the string library for handling text

using namespace std;

int main()
{
    string lineOfText;
    char firstCharacter, eleventhCharacter, middleCharacter;

    // Prompt the user to enter a line of text
    cout << "Enter a line of text:" << endl;
    getline(cin, lineOfText);  // Use getline to read the entire line

    // Check and print the first character if it exists
    if (lineOfText.length() > 0) {
        firstCharacter = lineOfText.at(0);
        cout << "The first character is: " << firstCharacter << endl;
    } else {
        cout << "No first character" << endl;
    }

    // Check and print the 11th character if it exists
    if (lineOfText.length() >= 11) {
        eleventhCharacter = lineOfText.at(10);  // Index starts at 0, so the 11th character is at position 10
        cout << "The 11th character is: " << eleventhCharacter << endl;
    } else {
        cout << "No 11th character" << endl;
    }

    // Check and print the middle character if the string has an odd length
    int length = lineOfText.length();
    if (length > 0) {
        if (length % 2 != 0) {
            middleCharacter = lineOfText.at(length / 2);
            cout << "The middle character is: " << middleCharacter << endl;
        } else {
            cout << "No middle character (even length)" << endl;
        }
    } else {
        cout << "No middle character (empty input)" << endl;
    }

    return 0;
}
