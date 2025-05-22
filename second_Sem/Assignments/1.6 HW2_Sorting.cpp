// Manage students’ records. 
// record has netID, a major and a GPA, maintained in parallel arrays. 

            // Read students’ data from a file 

// Loop on displaying the following menu of choices:

// List the top n students (1)
// Search for a student(2)
// Exit the program. (3)

// 1: prompt for value of n
// netID, major and GPA of the top n students will be listed
// student with highest GPA going down.

// 2: Prompt for netID. 
// If found, in the netID array,
// array index, major and GPA are displayed. 
// If not found, “Student not found” message is displayed.

// 3: Prints “Exiting\n” and terminates.

// a) Arrays definition
// Define these arrays in the main function (for consistency, please use the same names to make the grading easier):

            // const int NUM_ELMTS = 18;
            
            // // netID, major and GPA are parallel arrays
            // int netID[NUM_ELMTS]; // Original netID array
            // string major[NUM_ELMTS]; // Original major array
            // double GPA[NUM_ELMTS]; // Original GPA array

            // // sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
            // double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
            // int sortedNetIDbyGPA[NUM_ELMTS]; 
            // string sortedMajorbyGPA[NUM_ELMTS]; 
            
            // // sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays 
            // int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
            // string sortedMajorbyID[NUM_ELMTS]; 
            // double sortedGPAbyID[NUM_ELMTS];

            // b) Arrays initialization
            // Prompt user for file name; read file

            // c) File
            // student’s netID, student’s major, student’s GPA. 
            // ex: 1001 CS 3.8
            // No need for input validation

// number of records < NUM_ELMTS.

// d) Search for a student
// Perform both a linear search and a binary search + display

// The linear search is performed on the original array, netID[NUM_ELMTS].

// The binary search can only be performed on a sorted array, 
// performed on sortedNetIDbyID.

// To display the major and GPA of the student found -> SortedMajorbyID and sortedGPAbyID, == parallel to sortedNetIDbyID.

// Bubble Sort or Selection sort ->when elements of sortedNetIDbyID swap, 
// you should also swap the elements at the same indices of sortedMajorbyID and sortedGPAbyID.

// main function should display the number of iterations, for both linear search and binary search.

// e) List the top n students
// Sort the GPA array by GPA in sortedGPAbyGPA. 
// When swap elements of sortedGPAbyGPA, you should also swap the elements at the same indices of sortedMajorbyGPA and sortedNetIDbyGPA.

// if n greater than the number of students list all the students sorted by GPA, starting with the highest.

// f) Outline of main

            // Prompt the user for a file name.  

            // Open the file and read the data to initialize the netID, major and GPA arrays. If the file cannot be opened, print “Could not open file” and “Exiting\n” and terminate.   

            // Copy netID to sortedNetIDbyGPA, copy GPA to sortedGPAbyGPA and copy major to sortedMajorbyGPA. Sort sortedGPAbyGPA by GPA, while maintaining the parallelism of sortedNetIDbyGPA and sortedMajorbyGPA  

            // Copy netID to sortedNetIDbyID, copy GPA to sortedGPAbyID and copy major to sortedMajorbyID. Sort sortedNetIDbyID by ID, while maintaining the parallelism of sortedGPAbyID and sortedMajorbyID  

// Display the contents of all the arrays. use space of setw(7) between all the different variable

// Display the menu of choices, and perform the action selected by the user on the menu (search, list the top n students, or quit). If the user chooses “search”, the main function should call both the linear search and binary search functions, and display the result of both searches, along with the number of iterations.  

// The  main  function should loop on displaying the menu as long as the user does not choose to quit. If the user chooses to quit,  the program  should print “Exiting\n” and terminate.
// g) Display arrays
// GPAs should be displayed with a decimal point followed by 2 digits.


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    const int NUM_ELMTS = 18;
    
    int netID[NUM_ELMTS];
    string major[NUM_ELMTS];
    double GPA[NUM_ELMTS];
    
    // sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    int sortedNetIDbyGPA[NUM_ELMTS]; 
    string sortedMajorbyGPA[NUM_ELMTS]; 
    
    // sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays 
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    string sortedMajorbyID[NUM_ELMTS]; 
    double sortedGPAbyID[NUM_ELMTS];
    
    if(!inputFile)
    {
        cout << "Could not open file" << endl;
        cout << "Exiting\n";    
    }
    
    else    
    {
        int index = 0;
        while(inputFile >> netID[index] >> major[index] >> GPA[index])
        {
            index++;
        }
        
        for(int i = 0; i < index ; i++)
        {
            sortedGPAbyGPA[i] = GPA[i];
            sortedGPAbyID[i] = GPA[i];
            
            sortedNetIDbyGPA[i] = netID[i];
            sortedNetIDbyID[i] = netID[i];
    
            sortedMajorbyGPA[i] = major[i];
            sortedMajorbyID[i] = major[i];
        }
        
        
        
        modifiedSortGPA(sortedGPAbyGPA, sortedNetIDbyGPA, sortedMajorbyGPA, index);
        modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, index);
        
        cout << "Original arrays:\n";
        cout << "----------------\n";
        
        cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << "     " << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
        
        for (int i = 0; i < index; i += 2)
        {
            cout << setw(7) << i << setw(10) << netID[i] << setw(8) << major[i] 
             << setw(7) << fixed << setprecision(2) << GPA[i] << "     ";
             
            
            if (i + 1 < index) 
            {
            cout << setw(7) << i + 1 << setw(10) << netID[i + 1] << setw(8) << major[i + 1] 
                 << setw(7) << fixed << setprecision(2) << GPA[i + 1];
            }
    
            cout << endl;
        }
        
        cout << "Arrays Sorted by GPA:\n";
        cout << "----------------\n";
        
        cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << "     " << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
        
        for (int i = 0; i < index; i += 2)
        {
            cout << setw(7) << i << setw(10) << sortedNetIDbyGPA[i] << setw(8) << sortedMajorbyGPA[i] 
             << setw(7) << fixed << setprecision(2) << sortedGPAbyGPA[i] << "     ";
             
            
            if (i + 1 < index) 
            {
            cout << setw(7) << i + 1 << setw(10) << sortedNetIDbyGPA[i + 1] << setw(8) << sortedMajorbyGPA[i + 1] 
                 << setw(7) << fixed << setprecision(2) << sortedGPAbyGPA[i + 1];
            }
    
            cout << endl;
        }
        
        cout << "Arrays Sorted by NetID:\n";
        cout << "----------------\n";
        
        cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << "     " << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
        
        for (int i = 0; i < index; i += 2)
        {
            cout << setw(7) << i << setw(10) << sortedNetIDbyID[i] << setw(8) << sortedMajorbyID[i] 
             << setw(7) << fixed << setprecision(2) << sortedGPAbyID[i] << "     ";
             
            
            if (i + 1 < index) 
            {
            cout << setw(7) << i + 1 << setw(10) << sortedNetIDbyID[i + 1] << setw(8) << sortedMajorbyID[i + 1] 
                 << setw(7) << fixed << setprecision(2) << sortedGPAbyID[i + 1];
            }
    
            cout << endl;
        }
        
        int choice = -1;
        
        while(choice != 3)
        {
            cout << "***************" << endl;
            cout << "Menu of choices" << endl;
            cout << "***************" << endl;
            cout << "1 - List top n students" << endl;
            cout << "2 - Search on a netID" << endl;
            cout << "3 – Quit" << endl;
            
            cin >> choice;
            
            if(choice > 3 || choice < 1)
            {
                cout << "Invalid Choice" << endl;
            }
            
            else if (choice == 1)
            {
                int n = 0;
                cout << "Enter n: ";
                cin >> n;
                
                if(n < 1)
                {
                    cout << "Invalid number of students to list" << endl;
                }
                
                else if (n > index)
                {
                    n = index;
                }
                
                cout << "Top " << n << " students are: " << endl;
                cout << endl;
                
                for(int i = 0; i < n; i++)
                {
                    cout << "netID: " << sortedNetIDbyGPA[i] << ", major: " << sortedMajorbyGPA[i] << ", " << "GPA: " << sortedGPAbyGPA[i] << endl;
                }
                
            }
            
            else if (choice == 2)
            {
                int nID = 0;
                cout << "Enter netID: ";
                cin >> nID;
                
                int nIter = 0;
                int foundIndex = 0;
                
                cout << endl;
                
                cout << "Result of Linear Search: " << endl;
                cout << "------------------------" << endl;
                
                foundIndex = linearSearchID(netID, index, nID, nIter);
                
                if(foundIndex != -1)
                {
                    cout << "Student found at index " << foundIndex << ", GPA is " << sortedGPAbyID[foundIndex] << endl;
                    cout << "It took "<< nIter << " iterations" << endl;
                }
                
                else
                {
                    cout << "Student was not found" << endl;
                }

                
                cout << endl;
                nIter = 0;
                
                cout << "Result of Binary Search: " << endl;
                cout << "------------------------" << endl;
                
                foundIndex = binarySearchID(sortedNetIDbyID, index, nID, nIter);
                
                if(foundIndex != -1)
                {
                    cout << "Student found at index " << foundIndex << ", GPA is " << sortedGPAbyID[foundIndex] << endl;
                    cout << "It took "<< nIter << " iterations" << endl;
                }
                
                else
                {
                    cout << "Student was not found" << endl;
                }
                
                cout << endl;
            }
        }
        
        cout << "Exiting\n" << endl;
        
    }
    inputFile.close();
    return 0;
    
}

/* This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped
*/
void modifiedSortGPA(double sortedGPAbyGPA[], int sortedNetIDbyGPA[], string sortedMajorbyGPA[], int index)
{
        for(int i = 0; i < index - 1; i++)
        {
            int maxIndex = i;
            double gpaTemp = 0.0;
            int netIDTemp = 0;
            string majorTemp = "";
            for(int j = i + 1; j < index; j++)
            {
                if(sortedGPAbyGPA[j] > sortedGPAbyGPA[maxIndex])
                {
                    maxIndex = j;
                }
            }
            
            if(maxIndex != i)
            {
                gpaTemp = sortedGPAbyGPA[i];
                sortedGPAbyGPA[i] = sortedGPAbyGPA[maxIndex];
                sortedGPAbyGPA[maxIndex] = gpaTemp;
                
                netIDTemp = sortedNetIDbyGPA[i];
                sortedNetIDbyGPA[i] = sortedNetIDbyGPA[maxIndex];
                sortedNetIDbyGPA[maxIndex] = netIDTemp;
                
                majorTemp = sortedMajorbyGPA[i];
                sortedMajorbyGPA[i] = sortedMajorbyGPA[maxIndex];
                sortedMajorbyGPA[maxIndex] = majorTemp;
            }
        }
}

/* This function sorts array2 and maintains the parallelism
of array1 and array3
Whenever elements of array2 are swapped, the elements of array 1
and array3 at the same indices are also swapped
*/
void modifiedSortID(int sortedNetIDbyID[], double sortedGPAbyID[], string sortedMajorbyID[], int index)
{
        for(int i = 0; i < index - 1; i++)
        {
            int maxIndex = i;
            double gpaTemp = 0.0;
            int netIDTemp = 0;
            string majorTemp = "";
            for(int j = i + 1; j < index; j++)
            {
                if(sortedNetIDbyID[j] > sortedNetIDbyID[maxIndex])
                {
                    maxIndex = j;
                }
            }
            
            if(maxIndex != i)
            {
                netIDTemp = sortedNetIDbyID[i];
                sortedNetIDbyID[i] = sortedNetIDbyID[maxIndex];
                sortedNetIDbyID[maxIndex] = netIDTemp;
                
                gpaTemp = sortedGPAbyID[i];
                sortedGPAbyID[i] = sortedGPAbyID[maxIndex];
                sortedGPAbyID[maxIndex] = gpaTemp;
                
                majorTemp = sortedMajorbyID[i];
                sortedMajorbyID[i] = sortedMajorbyID[maxIndex];
                sortedMajorbyID[maxIndex] = majorTemp;
            }
        }
}


/* This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int linearSearchID(int netID[], int index, int nID, int &nIter)
{
    int foundIndex = -1;
    for(int i = 0; i < index; i++)
    {
        if(netID[i] == nID)
        {
            foundIndex = i;
            i = index; // force stopping of loop
        }
        nIter++;
    }
    
    return foundIndex;
}

/* This function implements binary search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int binarySearchID(int sortedNetIDbyID[], int index, int nID, int &nIter)
{
    int left = 0;
    int right = index - 1;
    int mid = 0;
    int foundIndex = -1;
    
    while (left <= right)
    {
        nIter++;
        mid = (left + right)/2;
        
        if(sortedNetIDbyID[mid] == nID)
        {
            foundIndex = mid;
            left = index + 1;  // force stopping of loop
        }
        
        else if (sortedNetIDbyID[mid] < nID)
        {
            left = mid + 1;
        }
        
        else
        {
            right = mid - 1;
        }
    }
    
    return foundIndex;
}






