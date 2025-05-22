/**
 * @file palindrome_detector.cpp
 * @brief This program reads lines of text and determines if each line is a palindrome.
 *
 * A palindrome is a string that reads the same forwards and backwards, ignoring
 * case and non-alphabetic characters. The program sanitizes input by removing
 * non-alphabetic characters and converting everything to lowercase, then checks
 * for palindrome properties.
 *
 * Input: Lines of text from the standard input, ending with an empty line.
 * Processing: Each line is sanitized and checked for palindrome properties.
 * Output: For each line, prints "Yes, palindrome" if it is a palindrome,
 *         otherwise prints "No, not palindrome".
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Removes all non-alphabetic characters from the input string and converts it to lowercase.
 * @param input The original string to be processed.
 * @return A new string containing only lowercase alphabetic characters.
 */
string sanitizeInput(const string& input)
{
    string sanitized = "";

    for (char c : input)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                sanitized += c + ('a' - 'A'); // Convert to lowercase
            }
            else
            {
                sanitized += c;
            }
        }
    }

    return sanitized;
}

/**
 * @brief Checks if a given string is a palindrome.
 * @param str The string to check, assumed to be sanitized (only lowercase alphabetic characters).
 * @return True if the string is a palindrome, false otherwise.
 */
bool isPalindrome(const string& str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

/**
 * @brief Reads lines from standard input, determines if each is a palindrome, and prints the result.
 */
void processInput()
{
    string line;

    while (getline(cin, line))
    {
        if (!(line.size() == 0)) // Check if the line is empty
        {
            string sanitized = sanitizeInput(line);

            if (isPalindrome(sanitized))
            {
                cout << "Yes, palindrome" << endl;
            }
            else
            {
                cout << "No, not palindrome" << endl;
            }
        }
    }
}

/**
 * @brief The main function of the program.
 * @return 0 to indicate successful execution.
 */
int main()
{
    processInput();
    return 0;
}
