// Call a function to calculate the sum of two matrix. 
// two 2D array of 3*3 
// initialize the values from 0 to 49 using a random generator. 

// Take seed as an input from user
// addMatrix(matrix1, matrix2, resultMatrix). 
// It should also call the function printResult (matrix1, matrix2, resultMatrix, +) and display the result as shown in the output.


// void addMatrix(int [ROW][COL], int [ROW][COL], int [ROW][COL]);
// void printResult(int [ROW][COL],int [ROW][COL], int [ROW][COL], char op);


// use setw(4) for the matrix output to display as shown below


#include <iostream>
#include <iomanip>
using namespace std;

void addMatrix(int arrOne[3][3], int arrTwo[3][3], int arrThree[3][3]);
void printResult(int arrOne[3][3],int arrTwo[3][3], int arrThree[3][3], char op);

int main()
{
    int arrOne[3][3];
    int arrTwo[3][3];
    int arrThree[3][3];
    
    char op = '+';
    
    int seed = 0;
    
    cout << "Enter in the seed value: ";
    cin >> seed;
    
    srand(seed);
    
    cout << "Matrix1 is : " << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrOne[i][j] = rand() % 50;
            cout << setw(4) << arrOne[i][j];
        }
        cout << endl;
    }

    cout << endl;

    cout << "Matrix2 is : " << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTwo[i][j] = rand() % 50;
            cout << setw(4) << arrTwo[i][j];
        }
        cout << endl;
    }    
    
    cout << endl;
    addMatrix(arrOne, arrTwo, arrThree);
    
    cout << endl;
    cout << "The addition of the matrices is" << endl;
    
    printResult(arrOne, arrTwo, arrThree, op);
}

void addMatrix(int arrOne[3][3], int arrTwo[3][3], int arrThree[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrThree[i][j] = arrOne[i][j] + arrTwo[i][j];
        }
    }
}

void printResult(int arrOne[3][3],int arrTwo[3][3], int arrThree[3][3], char op)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << setw(4) << arrOne[i][j];
        }
        
        if(i == 3/2)
        {
            cout << "   " << op << " ";
        }
        
        else
        {
            cout << "     ";
        }
        
        for(int j = 0; j < 3; j++)
        {
            cout << setw(4) << arrTwo[i][j];
        }

        if(i == 3/2)
        {
            cout << "    " << '=' << " ";
        }
        
        else
        {
            cout << "      ";
        }
        
        for(int j = 0; j < 3; j++)
        {
            cout << setw(4) << arrThree[i][j];
        }
        
        cout << endl;
    }
}
