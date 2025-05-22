/**
 * Lion.h
 * 
 * PSEUDOCODE:
 * 1. Define Lion class inheriting from Feline
 * 2. Override default constructor with Lion-specific behavior
 * 3. Override virtual methods: makeNoise, eat
 * 4. Implement Lion-specific behaviors and characteristics
 */

 #ifndef LION_H
 #define LION_H
 #include "Feline.h"
 #include <iostream>
 using namespace std;
 
 // Lion class - represents the "king" of the felines
 class Lion: public Feline
 {
     public:
     // Default constructor with Lion-specific initialization
     Lion() : Feline()
     {
         // Set specific picture for Lion objects
         setPicture("Lion");
         
         // Lion-specific introduction
         cout << "Lion: I am the king of my animal kingdom!!" << endl;
     }
     
     // Override makeNoise method for Lion-specific sound
     void makeNoise() override
     {
         // Lion's specific sound
         cout << "Lions roar!!" << endl;
         
         // Comment out parent class call for cleaner output
         //Feline::makeNoise();
     }
     
     // Override eat method for Lion-specific eating habits
     void eat() override
     {
         // Call parent class implementation first
         Feline::eat();
         
         // Add Lion-specific eating behavior
         cout << "Watch your back. My hunger gets impatient." << endl;
     }
 };
 #endif // LION_H