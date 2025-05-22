//==========================================================
// PSEUDOCODE FOR MAIN PROGRAM:
// 1. Create TestAnimal class that inherits from Animal
// 2. Test default constructor functionality
// 3. Test parameterized constructor functionality
// 4. Test copy constructor functionality
// 5. Test polymorphism using base class pointer
//==========================================================

#include "Animal.h"
#include <iostream>
using namespace std;

// Concrete implementation of the abstract Animal class
// Used for testing the Animal class functionality
class TestAnimal : public Animal {
public:
    // Default constructor - calls Animal's parameterized constructor with test values
    TestAnimal() : Animal("test", "testfood", 0, "testarea") {}
    
    // Parameterized constructor - passes values to Animal's constructor
    TestAnimal(string pic, string f, int h, string b) : Animal(pic, f, h, b) {}
    
    // Implementation of the pure virtual function from Animal
    // This is required to make TestAnimal a concrete (instantiable) class
    void makeNoise() override {
        cout << "TestAnimal noise! (" << getPicture() << " says hello)" << endl;
    }
};

int main() {
    cout << "=== Testing Animal functionality ===\n\n";
    
    //-------- Test 1: Default Constructor --------
    cout << "Creating test1 (default constructor):\n";
    TestAnimal test1;                  // Create using default constructor
    cout << test1 << endl;             // Test the << operator
    test1.makeNoise();                 // Test the makeNoise method
    test1.eat();                       // Test the eat method
    test1.roam();                      // Test the roam method
    test1.sleep();                     // Test the sleep method
    cout << endl;
    
    //-------- Test 2: Parameterized Constructor --------
    cout << "Creating test2 (parameterized constructor):\n";
    TestAnimal test2("dog", "bones", 5, "backyard");  // Create with specific values
    cout << test2 << endl;             // Test the << operator
    test2.makeNoise();                 // Test the makeNoise method
    test2.eat();                       // Test the eat method
    test2.setHunger(0);                // Test setter
    cout << "Hunger after eating: " << test2.getHunger() << endl << endl;  // Test getter
    
    //-------- Test 3: Copy Constructor --------
    cout << "Creating test3 (copy of test2):\n";
    TestAnimal test3(test2);           // Create as a copy of test2
    cout << test3 << endl;             // Test the << operator
    test3.setPicture("copied");        // Test setter - should not affect original
    test3.makeNoise();                 // Test the makeNoise method
    cout << endl;
    
    //-------- Test 4: Polymorphism --------
    cout << "Testing polymorphism:\n";
    // Create derived class object but reference it with base class pointer
    Animal* animalPtr = new TestAnimal("bird", "seeds", 2, "sky");
    animalPtr->print();                // Call virtual method through base pointer
    animalPtr->makeNoise();            // Call pure virtual method through base pointer
    animalPtr->eat();                  // Call virtual method through base pointer
    delete animalPtr;                  // Clean up dynamically allocated memory
    
    return 0;
}