/**
 * Dog.h
 * 
 * PSEUDOCODE:
 * 1. Define Dog class inheriting from Canine
 * 2. Override default constructor with Dog-specific behavior
 * 3. Implement parameterized constructor
 * 4. Override virtual methods: makeNoise, eat
 * 5. Implement Dog-specific behaviors and characteristics
 */

 #ifndef DOG_H
 #define DOG_H
 
 #include "Canine.h"
 #include <iostream>
 using namespace std;
 
 // Dog class - represents domesticated canines
 class Dog : public Canine 
 {
 public:
     // Default constructor with Dog-specific initialization
     Dog() : Canine()
     {
         // Set specific picture for Dog objects
         setPicture("Dog");
         
         // Dog-specific introduction
         cout << "Dog: I love being petted! I love cuddles!" << endl;
         cout << "I'd love my owner unconditionally!!" << endl;
     }
     
     // Parameterized constructor - passes parameters to parent
     Dog(const string& pic, const string& foodType, int hungryLevel, const string& boundaryArea)
     : Canine(pic, foodType, hungryLevel, boundaryArea)
     {
         // Set specific picture
         setPicture(pic);
         cout << "I am part of my animal kingdom with all parameters set!!" << endl;
     }
     
     // Override makeNoise method for Dog-specific sound
     void makeNoise() override {
         // Dog's specific sound
         cout << "WOOF WOOF" << endl;
         
         // Call parent class implementation
         Canine::makeNoise();
     }
     
     // Override eat method for Dog-specific eating habits
     void eat() override {
         // Call parent class implementation first
         Canine::eat();
         
         // Add Dog-specific eating behavior
         cout << "I am okay with dog food! I promise." << endl;
     }
 };
 #endif // DOG_H