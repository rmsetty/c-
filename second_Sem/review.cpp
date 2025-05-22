
struct Person
{
    string name = "hi";    
}

struct Student  //struct to create student objects with
{
    string x = "jo";
    string y = "momma";
    Person studPerson'//Creates object studPerson of Person-struct when Student object is made of Student-struct
}

int main()
{
    
    Student stu1; //Created object stu1 of Student struct
    
    //Pointer
    Student * hiPtr = &stu1;  //Created Pointer to stu1 on the stack
    cout << hiPtr << endl;    //Points to address of stu1
    cout << *hiPtr << endl;   //Points to value of stu1
    
    int myArr[5];  // Random Array

    int * arrPtr = myArr;     //Pointer to first element of array (Automatic)
    int * arrPtr[5] = &myArr;    //Pointer to entire array


    // Pass pointer value to a function that has an astrik as a parameter in the function's argument
    printStu3(hiPtr);

    //Creating pointer to array/int on heap (Dynamic allocation of an array)
    int* numPtr = new int;                          //When placing on heap, have to use "NEW" keyword (Pointer name is Variable name)
    Student* studPtr = new Student[numStudents];    
    
    cout << *studPtr << endl; //Give the value of the first (index 0) element in the array
    cout << studPtr << endl; //Give the address of the first index 0) element in the array
    
    cout << *studPtr + 2 << endl; //Gives the value of the third (index 2) element in the array
    cout << *studPtr + 2 << endl; //Gives the address of the third (index 2) element in the array


    for (int i = 0; i < numStudents; i++)       //Iterating through an array on the heap
    {
       printStu(*(studPtr + i));                //Pass pointer value to a function that doesn't have an astrik as a parameter in the function's argument 
    }

    delete [] studPtr; //If using heap, MUST delete info off of heap when done (Must delete befor setting to null)
    delete numPtr;
    hiPtr = nullPtr;   //Always set ALL pointers to nullPtr when done
    studPtr = nullPtr;
    numPtr = nullPtr;

    return 0;
}


void printStu(Student s) // Function that doesn't have an astrik as a parameter in the function's argument 
{
    cout << "Name: " << s.studPerson.name << endl;
}


void printStu3(Student *sPtr) // Function that has an astrik as a parameter in the function's argument
{
    cout << "Name: " << sPtr->studPerson.name << endl; // Same thing as *sPtr.studPerson.name (-> replaces the * and .) 
}