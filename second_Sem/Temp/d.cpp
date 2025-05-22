/*
begin  
    // declare variables  
    declare hoursWorked, payRate, grossPay as float  
    declare overtimeHours, overtimePay, totalPay as float  

    // get input from user  
    print "enter hours worked: "  
    input hoursWorked  
    print "enter hourly pay rate: "  
    input payRate  

    // validate input  
    if hoursWorked < 0 or payRate < 0 then  
        print "error: invalid input. hours and pay rate must be non-negative."  
        exit program  
    endif  

    // calculate regular pay  
    if hoursWorked <= 40 then  
        grossPay = hoursWorked * payRate  
        overtimePay = 0  
    else  
        // calculate overtime  
        overtimeHours = hoursWorked - 40  
        overtimePay = overtimeHours * (payRate * 1.5)  
        grossPay = 40 * payRate  
    endif  

    // compute total pay  
    totalPay = grossPay + overtimePay  

    // display output  
    print "regular pay: $", grossPay  
    print "overtime pay: $", overtimePay  
    print "total pay: $", totalPay  
end
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//constant for number of records
const int NUM_ELMTS = 18;

//function prototypes
int linearSearchID(int arr[], int numElems, int value, int &nIter);
int binarySearchID(int arr[], int numElems, int value, int &nIter);
void modifiedSortGPA(double array1[], int array2[], string array3[], int size);
void modifiedSortID(int array2[], double array1[], string array3[], int size);

int main() {
    
    //arrays that store the netID, major and GPA
    int netID[NUM_ELMTS];
    string major[NUM_ELMTS];
    double GPA[NUM_ELMTS];

    int sortedNetIDbyGPA[NUM_ELMTS];
    double sortedGPAbyGPA[NUM_ELMTS];
    string sortedMajorbyGPA[NUM_ELMTS];

    int sortedNetIDbyID[NUM_ELMTS];
    double sortedGPAbyID[NUM_ELMTS];
    string sortedMajorbyID[NUM_ELMTS];
    
    //gets the name of the file from the user
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    
    //input validation to see if the file opens
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "Could not open file\nExiting\n";
        return 1;
    }
    
    //reads the data from the file into the array
    int index = 0;
    while (inputFile >> netID[index] >> major[index] >> GPA[index]) {
        index++;
    }
    //closes file
    inputFile.close();
    
    //copys the data into sorted arrays
    for (int i = 0; i < index; i++)
    {
        sortedNetIDbyGPA[i] = netID[i];
        sortedGPAbyGPA[i] = GPA[i];
        sortedMajorbyGPA[i] = major[i];

        sortedNetIDbyID[i] = netID[i];
        sortedGPAbyID[i] = GPA[i];
        sortedMajorbyID[i] = major[i];
    }
    
    //calls the sort gpa and netID arrays
    modifiedSortGPA(sortedGPAbyGPA, sortedNetIDbyGPA, sortedMajorbyGPA, index);
    modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, index);
    
    //prints out the Original array 
    cout << "Original arrays:\n";
    cout << "----------------\n";
    
    cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << "     "
     << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
    
    //prints it use a table format
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
    
    //dispalys the storted array by gpa
    cout << "\nArrays sorted by GPA:\n";
    cout << "---------------------\n";
    
    cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << "     "
     << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
     
     //prints the gpa data
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
    
    //displays the sorted array by netID
    cout << "\nArrays sorted by netID:\n";
    cout << "-----------------------\n";
    
    cout << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA"
     << setw(7) << "index" << setw(10) << "netID" << setw(8) << "major" << setw(7) << "GPA" << endl;
     
     //prints the ID-sorted data
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
    
    //menu for the user to enter their choice
    int choice;
    do {
        cout << "\n***************\nMenu of choices\n***************\n";
        cout << "1 - List top n students\n2 - Search on a netID\n3 - Quit\n";
        cin >> choice;
        
        //displays the top n students 
        if (choice == 1) 
        {
            //gets the number from the user
            int n;
            cout << "Enter n: ";
            cin >> n;
            
            //makes sure the number dosent go beyond the number of students
            if (n > index) 
            {
                n = index;
            }

            cout << "\nTop " << n << " students are:\n\n";
            
            //prints the top students
            for (int i = n-1; i >= 0; i--) 
            {
                cout << "netID: " << sortedNetIDbyGPA[i] << ", major: " << sortedMajorbyGPA[i]
                     << ", GPA: " << fixed << setprecision(2) << sortedGPAbyGPA[i] << endl;
            }
        }
        
        //searches for specific netID
        else if (choice == 2) 
        {
            //gets the netID from the user
            int searchNetID;
            cout << "Enter netID: ";
            cin >> searchNetID;
            
            //calls the linearSearchID and binarySearchID methods
            int linearTimes = 0;
            int binaryTimes = 0;
            int linearIndex = linearSearchID(netID, index, searchNetID, linearTimes);
            int binaryIndex = binarySearchID(sortedNetIDbyID, index, searchNetID, binaryTimes);

            cout << "\nResult of linear search:\n";
            cout << "------------------------\n";
            
            //prints the results for the linear search
            if (linearIndex != -1) 
            {
                cout << "Student found at index " << linearIndex << ", GPA is " << fixed << setprecision(2) << GPA[linearIndex] << endl;
            } 
            else 
            {
                cout << "Student not found\n";
            }
            cout << "It took " << linearTimes << " iterations\n";
            
            //prints the results of binary search
            cout << "\nResult of binary search:\n";
            cout << "------------------------\n";
            
            if (binaryIndex != -1) 
            {
                cout << "Student found at index " << binaryIndex << ", GPA is " << fixed << setprecision(2) << sortedGPAbyID[binaryIndex] << endl;
            }
            else
            {
                cout << "Student not found\n";
            }
            
            cout << "It took " << binaryTimes << " iterations\n";
        } 
        
        //if the enters 3 quits the program
        else if (choice == 3)
        {
            cout << "Exiting\n";
        } 
        //if the user enters anything else shows the menu again
        else
        {
            cout << "Invalid choice, please try again.\n";
        }
    } 
    while (choice != 3);

    return 0;
}

int linearSearchID(int arr[], int numElems, int value, int &nIter) 
{
    //loops through the num of elements
    nIter =0;//counter
    for (int i = 0; i < numElems; i++) 
    {
        nIter++;
        //if i equals value then returns the index its found
        if (arr[i] == value) 
        {
            return i;
        }
    }
    return -1;
}

int binarySearchID(int arr[], int numElems, int value, int &nIter) 
{
    //uses binary search to find the netID in the array
    nIter = 0;
    int low = 0;
    int high = numElems - 1;
    while (low <= high) 
    {
        nIter++;
        int middle = low + (high - low) / 2;
        if (arr[middle] == value) 
        {
            return middle;
        }
        else if (arr[middle] < value) 
        {
            low = middle + 1;
        } 
        else 
        {
            high = middle - 1;
        }
    }
    return -1;
}

void modifiedSortGPA(double array1[], int array2[], string array3[], int size) 
{
    //sorts the array by gpa 
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            //compares gpa f
            if (array1[j] > array1[j + 1])
            {
                double gpa = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = gpa;

                int netId = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = netId;

                string major = array3[j];
                array3[j] = array3[j + 1];
                array3[j + 1] = major;
            }
        }
    }
}

void modifiedSortID(int array2[], double array1[], string array3[], int size) 
{
    //sorts arrays based on netID
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            //compares netIDs
            if (array2[j] > array2[j + 1])
            {
                int netId = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = netId;

                double gpa = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = gpa;

                string major = array3[j];
                array3[j] = array3[j + 1];
                array3[j + 1] = major;
            }
        }
    }
}
