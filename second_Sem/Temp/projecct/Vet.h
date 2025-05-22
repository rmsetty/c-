/**
 * Vet.h
 * 
 * PSEUDOCODE:
 * 1. Define Vet class that interacts with Animal objects
 * 2. Implement default constructor
 * 3. Implement giveShot method that takes an Animal reference
 * 4. Method triggers Animal's makeNoise response
 */

 #ifndef VET_H
 #define VET_H
 #include "Animal.h"
 #include <iostream>
 using namespace std;
 
 // Vet class - represents a veterinarian who treats animals
 class Vet
 {
     public:
         // Default constructor with Vet-specific introduction
         Vet()
         {
             cout << "Hey I am the Vet for treating your animals!!" << endl;
         }
         
         // Method to give a shot to any Animal type (polymorphism)
         // Stimulates animal's reaction to receiving a shot
         void giveShot(Animal &animalPatient)
         {
             cout << "I am going to give a shot." << endl;
             cout << "Please bear with me baby." << endl;
             
             // This will call the appropriate makeNoise method 
             // based on the actual animal type
             animalPatient.makeNoise();
         }
 };
 #endif // VET_H