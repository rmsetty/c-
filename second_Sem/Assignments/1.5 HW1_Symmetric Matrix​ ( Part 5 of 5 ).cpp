// Determine whether a given matrix is symmetric.

// 4 6 8 10 12

// 6 9 11 13 15

// 8 11 13 15 17

// 10 13 15 17 19

// 12 15 17 19 21

// The matrix is symmetrical.

#include <iostream>

using namespace std;

int main()
{
    int row = 0;
    int col = 0;
    
    cout << "Enter the number of rows and columns: ";
    cin >> row;
    cin >> col;
    
    int matrix[row][col];
    
    bool symmetrical = true;
    
    cout << "Enter the values for the matrix: ";
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                symmetrical = false;
            }
        }
    }
    
    if (symmetrical == false)
    {
        cout << "The matrix is not symmetrical.";
    }
    
    else
    {
         cout << "The matrix is symmetrical.";
    }
    
}