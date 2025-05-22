/**
 * Wolf.h
 * 
 * PSEUDOCODE:
 * 1. Define Wolf class inheriting from Canine
 * 2. Implement default constructor with Wolf-specific initializations
 * 3. Implement parameterized constructor
 * 4. Override virtual method: makeNoise
 * 5. Implement Wolf-specific behaviors and characteristics
 */

 #ifndef WOLF_H
 #define WOLF_H
 #include "Canine.h"
 #include <iostream>
 using namespace std;
 
 // Wolf class - represents wild canines
 class Wolf : public Canine
 {
     public:
     // Default constructor with Wolf-specific initialization
     Wolf() : Canine()
     {
         // Set specific picture for Wolf objects
         setPicture("Wolf");
         
         // Wolf-specific introduction
         cout << "Wolf: Why don't take me as your pet? Why is dog so special?" << endl;
     }
     
     // Parameterized constructor - passes parameters to parent
     Wolf(const string& pic, const string& foodType, int hungryLevel, const string& boundaryArea)
     : Canine(pic, foodType, hungryLevel, boundaryArea)
     {
         cout << "I am part of my animal kingdom with all parameters set!!" << endl;
     }
     
     // Override makeNoise method for Wolf-specific sound
     void makeNoise() override
     {
         // Wolf's specific sound
         cout << "Wolves howl, cry and yell!!" << endl;
         
         // Call parent class implementation
         Canine::makeNoise();
     }
 };
 #endif // WOLF_H