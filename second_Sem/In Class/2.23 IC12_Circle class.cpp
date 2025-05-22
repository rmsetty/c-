// Circle Class
// Takes double radius as a private member

// 4 Private Functions

//   void setRadius(double);
//   double getRadius() const;
//   double getDiameter() const;
//   double getArea() const;

// Input radius from user. 
// Make circle object c1. 
// Set radius for the c1 object 
// Print the data of c1 object. 

// Instantiate pointer to object c2. 
// Set the radius through the c2 object 
// print data through the pointer

#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle
{
    private:
        double radius;
        
    public:
        void setRadius(double r) {radius = r;};
        double getRadius() const {return radius;};
        double getDiameter() const {return radius * 2;};
        double getArea() const {return PI * radius * radius;};
};

int main()
{
    cout << "This program will calculate the area of a circle." << endl;
       
    int radius = 0;
    cout << "Enter radius for c1: ";
    cin >> radius;
    

    Circle c1;
    cout << "Here is c1's Data: " << endl;
    c1.setRadius(radius);
    cout<<c1.getRadius() << endl;
    cout<<c1.getDiameter()<<endl;
    cout<<c1.getArea() <<endl;
    
    int radius1 = 0;
    cout << "Enter radius for c2: ";
    cin >> radius1;
    
    Circle c2;
    
    Circle* c2Pointer = &c2;
    c2Pointer->setRadius(radius1);
    
    cout << c2Pointer->getRadius() << endl;
    cout << c2Pointer->getDiameter() << endl;
    cout << c2Pointer->getArea() << endl;
    
}