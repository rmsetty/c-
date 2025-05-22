//Headers to Know
#include <iostream> //
#include <iomanip>
#include <cmath>
#include <fstream>

//Stream Objexts -> ifstream and ofstream -> All stream objects must be passed by reference

//Calling values passed by value -> You basically cannot pass an array by value -> Passing array by value is same as passing array by reference
function(string str, int num, double dec, char ch, int arr[])

//Calling values passed by const and value
function(const string str, const int num, const double dec, const char ch, const int arr[])

//Calling values passed by reference -> Passing an array by reference doesn't need '&' symbol. 
function(string& str, int& num, double& dec, char& ch, int arr[], ifstream& inputfile, ofstream& outputfile)

//Calling values passed by const and reference -> Don't pass ofstream object as const, because it's meant to be modified, not read like the ifstream object
function(const string& str, const int& num, const double& dec, const char& ch, const int arr[], const ifstream& inputfile, ofstream& outputfile)


//Formatting Output (Only have to set it once, and it'll affect all values)///////////

int number = 19193484.2843893;
int x = 8434832.483943;
int y = 1295839.98534738;

cout << fixed << right << showpoint << setprecision(0) << endl;

cout << number << endl;
cout << x << endl;
cout << y << endl;

//Formatting Output (Must set it every time, to affect all values)///////////////////

int number = 19193484.2843893;
int x = 8434832.483943;
int y = 1295839.98534738;

cout << setw(0) << number << setw(0) << x << endl;
cout << setw(0) << y << endl;

//Opening and reading a file////////////////////////////////////////////////////////
ifstream variableName(fileName);

//Opening and modifying a file////////////////////////////////////////////////////////
ofstream variableName(fileName);

//Checking if the files are opening////////////////////////////////////////////////
if(!variableName1.open())
{
    cout << "Error" << endl;
}

if(!variableName2.open())
{
    cout << "Error" << endl;
    if (variableName1.open()) //Close the opened first file if the second file isn't opening
    {
        variableName1.close();
    }
}

//If they give you the number of elements in a file and you need to enter a file into an array///////
for(int i = 0; i < size; i++)
{
    inputfile >> array[i];
}

//Finding the number of elements in a file when not given to you -> Number of bytes/byte of one element
int size = sizeof(arr)/sizeof(arr[0]);

//If they don't give you the number of elements in a file and you need to enter a file into an array////
int count = 0;

while (inputfile>>array[count])
{
    count++
    if(count == MAX)
    {
        cout << "Error" << endl;
    }
}

//When wanting to reverse values in a an arrays/////////////////////////////
int end = start + moves - 1;
while(start < end)
[
    swap(array[start], array[end])

    start++;
    end--;
]

//When needing to reverse/swap values in an array, but can't use the swap method from the utility header (Custom swap method)////////
array[a] = array[a] + array[b]; // -> Makes A + B
array[b] = array[a] - array[b]; // -> Makes A + B - B
array[a] = array[a] - array[b];// -> 

//Shfiting/Rotating an Array
steps = steps % totalElements // -> equals to the marker of when to stop reversing

reverse(0, elements) // -> Reverse entire array

reverse(0, steps) // -> Reverse from start to whenever

reverse(steps, elements - steps) // -> Reverse from wherever to the end

//When needing to transpose a matrix
array[row][column] = array[column][row]

//When needing to do a Upper Triangle Traversal of a Matrix
for(int i = 0; i < size; i++)
{
    for(int j = i; j < size; j++)
    {
        cout;
    }
}

//When needing to do a Lower Triangle Traversal of a Matrix
for(int i = 0; i < size; i++)
{
    for(int j = 0; j <= i; j++)
    {
        cout;
    }
}

//When needing to do a Diagonol of a Matrix
for(int i = 0; i < size; i++)
{
    array[i][i];
}

//Determining if a Matrix is Symmetrical in terms of switching rows and cols
bool symmetric;
if(array[row][col] == array[col][row])
{
    symmetric = true;
}
else
{
    symmetric = false;
}


