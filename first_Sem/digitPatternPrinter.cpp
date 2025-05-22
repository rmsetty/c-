#include <iostream>

using namespace std;

int getInput()
{
    int input;
    while (!((input > -1) || (input < 10)))
    {
        cout << "Enter a decimal digit: " << endl;
        cin >> input;
        if(!((input > -1) || (input < 10)))
        {
            cout << "Error: " << endl;
        }

    }    

    while(true)
    {
        cout << "Enter a decimal digit: " << endl;
        cin >> input;
    }

    return input;
}

int main()
{
    int input = getInput();

    for (int i = input, i > -1, i--)
    {
        for (int i = input, i > -1, i--)
        {
            cout << i;
        }
        
        cout << "" << endl;
    }

    return 0;
}