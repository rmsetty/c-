// Patinet Record has the following details.

// ID - A unique integer denoting a patient ID
// FName - A string to store the first name of the student
// LName - A string to store the last name of the student
// Vitals - A int array that will store just patient’s vitals like BP, Sugar, Pulse

// Define Structure for Patient. 
// Create a pointer to the array of structures. 
// Access this array through the pointer. 
// Read from patientsInfo.txt all the patients information and store it in a dynamic array of structures. Print the values. 
// Int values should be printed with setw(4) and Strings be printed with setw(10). All fields be left justified. 
// If you follow this format. your output will print like the output shown.

// Expected Output
// Enter filename: patientsinfo.txt
// ID  FN        LN        BPU BPL Pulse
// 1   Sri       Sri       120 80  84  
// 8   Ala       Sri       130 87  90  
// 4   Jey       kes       150 97  92  
// 7   Priya     Kes       180 87  96  
// 3   Leo       Mathew    110 87  90  
// 11  Luis      Cast      120 80  84  
// 18  Arg       Jose      130 87  90  
// 14  Rylie     How       150 97  92  
// 17  Pat       Will      180 87  96  
// 13  Leo       Zach      110 87  90  

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    struct Patient
    {
        int ID;
        string FName;
        string LName;
        int vitals[3];
    };
    
    string fileName = "";
    cout << "Enter file name: ";
    cin >> fileName;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    if(!inputFile)
    {
        cout << "Error opening file: " << endl;
    }
    
    else
    {
        string line;
        getline(inputFile, line);
        
        int lineCount = 0;
        while(getline(inputFile, line))
        {
            lineCount++;
        }
        
        Patient* patients = new Patient[lineCount];
        
        inputFile.clear();
        inputFile.seekg(0);
        
        getline(inputFile, line);
        
        for(int i = 0; i < lineCount; i++)
        {
            inputFile >> (patients + i)->ID >> (patients + i)->FName >> (patients + i)->LName >> (patients + i)->vitals[0] >> (patients + i)->vitals[1] >> (patients + i)->vitals[2];
        }
        
        cout << left;
        cout << "ID" << setw(4) << "FN" << setw(10) << "LN" << setw(10) << "BPU" << setw(4) << "BPL" << setw(4) << "Pulse" << endl;
        for(int i = 0; i < lineCount; i++)
        {
            cout << (patients + i)->ID << setw(4) << (patients + i)->FName << setw(10) << (patients + i)->LName << setw(10) << (patients + i)->vitals[0] << setw(4) << (patients + i)->vitals[1] << setw(4) << (patients + i)->vitals[2] << endl;
        }
        
        inputFile.close();
        delete[] patients;
        patients = nullptr;
    }
    
    return 0;
}




