/**
 * @file replace.cpp
 * @brief This program replaces every occurrence of a specified character in a given 
 *        string with a replacement string and returns the modified result.
 * 
 * The program contains a replace function that takes an original string, a character to replace, 
 * and a replacement string. It replaces all occurrences of the specified character in the original 
 * string with the replacement string and returns the modified result. The program includes a main 
 * function for testing replace function with different test cases.
 *
 * Input: A string to modify, a character to replace, and a replacement string.
 * Process: Replaces each occurrence of the specified character with the replacement string.
 * Output: A new string with specified characters replaced as per the given inputs.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Replaces every occurrence of a specified character in the input string
 *        with a replacement string and returns the modified result.
 * 
 * @param original The original string to modify (passed by const reference).
 * @param charToReplace The character in the original string to replace.
 * @param replacement The string that replaces each occurrence of charToReplace.
 * @return A new string with the specified character replaced by the replacement string.
 */
string replace(const string &original, char charToReplace, const string &replacement) 
{
    string result;  // Initialize an empty result string to build the modified string

    for (char ch : original) // Loop through each character in the original string
    {
        if (ch == charToReplace)
        {
            result += replacement;  // If match, add replacement string
        } 
        else 
        {
            result += ch;  // Otherwise, add the original character
        }
    }

    return result;  // Return the fully modified string
}

int main() 
{
    // Test cases for the replace function
    string test1 = replace("abcd", 'c', "123");
    cout << "replace(\"abcd\", 'c', \"123\") -> " << test1 << endl;

    string test2 = replace("xx", 'x', "hots");
    cout << "replace(\"xx\", 'x', \"hots\") -> " << test2 << endl;

    string test3 = replace("Argon", 'r', "");
    cout << "replace(\"Argon\", 'r', \"\") -> " << test3 << endl;

    return 0;
}
