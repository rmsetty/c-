// Calculate  sum of all the numbers in both the diagonals. 
// create a 2D array of 4*4 
// Initialize the values from 0 to 49 using a random generator. 
// Take seed as an input from user
// Use srand(seed) instead of srand(time(0)). 
// call the function sumMajorDiagonal (A) and display the Sum of elements along the major diagonal. 
// call the function sumOtherDiagonal (A) and display the Sum of elements along the other diagonal

#include <iostream>
#include <iomanip>

using namespace std;

int sumMajorDiagonal(int arr[4][4])
{
    // 00 11 22 33
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        sum += arr[i][i];
    }
    
    return sum;
}

int sumOtherDiagonal(int arr[4][4]) 
{
    // 03 12 21 30
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        sum += arr[i][3 - i];
    }
    return sum;
}


int main()
{
    const int MAXROWS = 4;
    const int MAXCOLS = 4;
    
    int arr[MAXROWS][MAXCOLS];
    int seed = 0;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    srand(seed);
    
    for(int i = 0; i < MAXROWS; i++)
    {
        for(int j = 0; j < MAXCOLS; j++)
        {
            arr[i][j] = rand() % 50;
            cout  << setw(4) << arr[i][j];
            if((j + 1) % 4 == 0)
            {
                cout << endl;
            }
        }
    }
    
    cout << sumMajorDiagonal(arr) << endl;
    cout << sumOtherDiagonal(arr) << endl;
    
    return 0;
}










