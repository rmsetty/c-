// Function to generate random password based on requirements passed as arguments. 
//  If the requirement cannot be satisfied, return "invalid".

// // minimum & maximum length, minimum # of lower case letters, minimum # of upper case letters, 
// // minimum # of digits (0-9), minimum # of special characters (!@#$%^&*+:;)

#include <iostream>

using namespace std;

string generatePassword(int minLength, int maxLength, int minLower, int minUpper, int minDigits, int minSpecial);

int main()
{
    
    srand(time(0));
    
    int minLength, maxLength, minLower, minUpper, minDigits, minSpecial = 0;
    
    cout << "Enter the minimum length, maximum length, the lower, uppper, the minimum digits, and the minimum speical characters." << endl;
    cin >> minLength >> maxLength >> minLower >> minUpper >> minDigits >> minSpecial;
    
    string password = generatePassword(minLength, maxLength, minLower, minUpper, minDigits, minSpecial);
    
    cout << password<< endl;
    
    return 0;
}

string generatePassword(int minLength, int maxLength, int minLower, int minUpper, int minDigits, int minSpecial)
{
    int requiredChars = minLower + minUpper + minDigits + minSpecial;
    string password = "";
    if((minLength > maxLength) || (requiredChars > maxLength))
    {
        cout << "Invalid" << endl;
    }
    
    else
    {
        int passwordLength = max(requiredChars, minLength);
        
        string lowers = "abcdefghijklmnopqrstuvwxyz";
        string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string digits = "1234567890";
        string specials = "!@#$%^&*()_+-=[]{}|;:',.<>/?";
        string allChars = lowers + uppers + digits + specials;
        
        for(int i = 0; i < minLower; i++)
        {
            password += lowers[rand() % lowers.length()];
        }
        
        for(int i = 0; i < minUpper; i++)
        {
            password += uppers[rand() % uppers.length()];
        }

        for(int i = 0; i < minDigits; i++)
        {
            password += digits[rand() % digits.length()];
        }
        
        for(int i = 0; i < minSpecial; i++)
        {
            password += uppers[rand() % uppers.length()];
        }
        
        while(password.length() < passwordLength)
        {
            password += allChars[rand() % allChars.length()];
        }
        
    }
    
    return password;
}