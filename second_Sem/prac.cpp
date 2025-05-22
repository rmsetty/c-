#include <iostream>
#include <string>

using namespace std;

struct Person 
{
    string name;
    int bMonth;
    int bDay;
    int bYear;
};

struct Student 
{
    Person studPerson;
    double GPA;
};

Student getStudentInfo();
void printStu(Student stu1);
void printStu2(Student &stu1);
void printStu3(const Student * const stu1);

int main()
{
    Student stu1 = getStudentInfo();
    int numStudents;
    printStu(stu1);
    printStu2(stu1);
    
    Student *sPtr = &stu1;
    
    printStu3(sPtr);
    
    cout << "Address of " << stu1.studPerson.name << ": " << &stu1 << endl;
    
    cout << "Enter in the number of students: " << endl;
    cin >> numStudents;
    
    sPtr = new Student[numStudents];
    
    for(int i = 0; i < numStudents; i++)
    {
        *(sPtr + i) = getStudentInfo();
    }
    
    for(int i = 0; i < numStudents; i++)
    {
        printStu3(sPtr + i);
    }
    
    delete [] sPtr;
    
    return 0;
    
}

Student getStudentInfo()
{
    Student s;
    cout << "Enter name: " << endl;
    getline(cin, s.studPerson.name);
    cout << "Enter your birthday: " << endl;
    cin >> s.studPerson.bMonth >> s.studPerson.bDay >> s.studPerson.bYear;
    cin.ignore();
    cout << "Enter in your GPA: " << endl;
    cin >> s.GPA;
    cin.ignore();
    return s;
}

void printStu(Student stu1)
{
    cout << "Name: " << stu1.studPerson.name << ", DOB " << stu1.studPerson.bMonth
     << "/" << stu1.studPerson.bDay << "/" << stu1.studPerson.bYear
     << ", GPA: " << stu1.GPA << endl;
}

void printStu2(Student &stu1)
{
    cout << "Name: " << stu1.studPerson.name << ", DOB " << stu1.studPerson.bMonth
     << "/" << stu1.studPerson.bDay << "/" << stu1.studPerson.bYear
     << ", GPA: " << stu1.GPA << endl;
}

void printStu3(const Student * const stu1)
{
    cout << "Name: " << stu1->studPerson.name << ", DOB " << stu1->studPerson.bMonth
     << "/" << stu1->studPerson.bDay << "/" << stu1->studPerson.bYear
     << ", GPA: " << stu1->GPA << endl;    
}





