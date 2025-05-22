// Performs input validation when reading grocery product records from a file. 

// Each Record:
// - PLU code (string)
// - Product Name (string)
// - Product Sales Type (0 = per unit, 1 = per pound)
// - Price per Pound or price per unit (double)
// - Current Inventory Level (pounds or units) (double)

// A001 Apples 1 0.90 21

// Input Validation 
// File - valid content
// 1. It has exactly 5 items on the same line
// 2. The first item should be a PLU. It is valid if and only if it contains only letters or digits, and is 4 characters long
// 3. The second item should be product name. It is valid if and only if the first character is a letter
// 4. The third item should be a sales type. It is valid if and only if it is only one character, and the character is a 1 or a 0
// 5. The fourth item should be a unit price. It is valid if and only if it contains only digits and at most one dot. If there is a dot, there are at most two digits after the dot
// 6. The fifth item should be the inventory level. It is valid if and only if it contains only digits

// File - invalid content + reason

// Break each line into token (seperated by space) (istringstream)


// /* Returns true if the string is a valid price, false otherwise 
// */
// bool isValidPrice(string); 

// /* Takes as reference parameter a string to be tokenized and returns the first token found
// Returns the empty string if no token is found
// The function deletes any leading delimiter and the first token found from the original string
// Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), ‘\n’ (new line) or ‘\r’ (carriage return)  character  
// Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
// the string s to become "\t\t 345\t ^7$ " 
// */ 
// string tokenize(string &); 
// Loop over s (delimiter + end is not reached) 
// Remove any leading delimiter(s)  
// Loop over the remaining characters as long as they are not a delimiter and the end of s is not reached // Extract the first token found
//     store the characters into token  
// Delete the first n characters from s  // n is the number of characters looped over in the two above loops  
// Return token  
// Your code will have to underline the message "Checking in.txt", "Checking in0.txt", etc. with a string of '-' (refer to the screen outputs), but the length of the string depends on the file name. To determine the proper length to print, apply the .length() member function to the message.



// Outside loop read line by line (getline(inFile, stringRead))  
//     inner loop: call tokenize to tokenize each line 
//       count # tokens  
//       token > 5 or token < 5, print appropriate error message + terminate  
//       if token is invalid, print the appropriate error message(s) + terminate  
// If all validations are successful, print a message to indicate the file is valid 
// Detect end of file when getline returns an empty string
// Appropriate validation logic based on the token counter. (PLU validation for PLU)
// End with a new line


#include <iostream>

using namespace std;

bool isValidPrice(string); 
string tokenize(string &);

int main()
{
    
    string fileName;
    string line;
    bool isValid = true;
    
    cout << "Enter input file: ";
    cin >> fileName;
    
    cout << endl;
    
    cout << "Checking " << fileName << endl;
    cout << "---------------" << endl;
    
    cout << endl;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    int tokenCount;
    string token;
    
    if (!inputFile)
    {
        cout << "Can't open file" << endl;
    }
    
    else
    {
        while(getline(inputFile, line) && isValid)
        {
            tokenCount = 0;
            originalString = line;
            token = tokenize(line);
            
            if(!token.empty())
            {
                tokenCount++;
                
                if(token == 1)
                {
                    
                }
            }
        }
    }
}

bool isValidPrice(string); 

/* Takes as reference parameter a string to be tokenized and returns the first token found
Returns the empty string if no token is found
The function deletes any leading delimiter and the first token found from the original string
Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), ‘\n’ (new line) or ‘\r’ (carriage return)  character  
Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
the string s to become "\t\t 345\t ^7$ " 
*/ 
string tokenize(string &); 
// Loop over s (delimiter + end is not reached) 
// Remove any leading delimiter(s)  
// Loop over the remaining characters as long as they are not a delimiter and the end of s is not reached // Extract the first token found
//     store the characters into token  
// Delete the first n characters from s  // n is the number of characters looped over in the two above loops  
// Return token  
// Your code will have to underline the message "Checking in.txt", "Checking in0.txt", etc. with a string of '-' (refer to the screen outputs), but the length of the string depends on the file name. To determine the proper length to print, apply the .length() member function to the message.



