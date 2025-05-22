/**
 * Tiger.h
 * 
 * PSEUDOCODE:
 * 1. Define Tiger class inheriting from Feline
 * 2. Implement default constructor with Tiger-specific initializations
 * 3. Implement parameterized constructor
 * 4. Override virtual methods: makeNoise, eat
 * 5. Implement Tiger-specific behaviors and characteristics
 */

 #ifndef TIGER_H
 #define TIGER_H
 #include "Feline.h"
 #include <iostream>
 using namespace std;
 
 // Tiger class - represents the "queen" of the felines
 class Tiger : public Feline
 {
     public:
     // Default constructor with Tiger-specific initialization
     Tiger() : Feline()
     {
         // Set specific picture for Tiger objects
         setPicture("Tiger");
         
         // Tiger-specific introduction
         cout << "Tiger: I am the queen of my animal kingdom!!" << endl;
     }
     
     // Parameterized constructor - passes parameters to parent
     Tiger(const string& pic, const string& foodType, int hungryLevel, const string& boundaryArea)
     :Feline(pic, foodType, hungryLevel, boundaryArea)
     {
         cout << "I am part of my animal kingdom with all parameters set!!" << endl;
     }
     
     // Override makeNoise method for Tiger-specific sound
     void makeNoise() override
     {
         // Tiger's specific sound
         cout << "GROWL!!" << endl;
         
         // Comment out parent class call for cleaner output
         //Feline::makeNoise();
     }
     
     // Override eat method for Tiger-specific eating habits
     void eat() override
     {
         // Call parent class implementation first
         Feline::eat();
         
         // Add Tiger-specific eating behavior
         cout << "As queen, I deserve the finest of meat." << endl;
     }
 };
 #endif // TIGER_H