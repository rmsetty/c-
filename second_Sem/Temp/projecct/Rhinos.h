/**
 * Rhinos.h
 * 
 * PSEUDOCODE:
 * 1. Define Rhinos class inheriting directly from Animal
 * 2. Implement default constructor with Rhino-specific initializations
 * 3. Implement parameterized constructor
 * 4. Override virtual methods: makeNoise, eat
 * 5. Implement Rhino-specific behaviors and characteristics
 */

 #ifndef RHINO_H
 #define RHINO_H
 #include "Animal.h"
 #include <iostream>
 using namespace std;
 
 // Rhinos class - represents rhinoceros animals
 class Rhinos: public Animal
 {
     public:
     // Default constructor with Rhino-specific initialization
     Rhinos() : Animal() 
     {
         // Set specific attributes for Rhino objects
         setPicture("Rhino");
         setFood("Veg");
         setHunger(10);
         setBoundaries("Water");
         
         // Rhino-specific introduction
         cout << "Rhinos: I am super friendly! Just be careful of my huge horn!!" << endl;
     }
     
     // Parameterized constructor - passes parameters to parent
     Rhinos(const string& pic, const string& foodType, 
     int hungryLevel, const string& boundaryArea): Animal(pic, foodType, hungryLevel, boundaryArea)
     {
         cout << "I don't harm anyone. I pose good for pictures!!" << endl;
     }
     
     // Override makeNoise method for Rhino-specific sound
     void makeNoise() override
     {
         cout << "Rhinos bellow!!" << endl;
     }
     
     // Override eat method for Rhino-specific eating habits
     void eat() override
     {
         cout << "From R: I am a vegetarian." << endl;
         cout << "I can eat even the grass, but please don't serve me Non-veg!!" << endl;
     }
 };
 #endif // RHINO_H