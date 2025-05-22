/**
 * Canine.h
 * 
 * PSEUDOCODE:
 * 1. Define Canine class inheriting from Animal
 * 2. Inherit all constructors from Animal
 * 3. Override default constructor with specific behavior
 * 4. Override virtual methods: makeNoise, eat, roam
 * 5. Implement Canine-specific behaviors and characteristics
 */

 #ifndef CANINE_H
 #define CANINE_H
 
 #include "Animal.h"
 #include <iostream>
 using namespace std;
 
 // Canine class - represents all canine animals (dogs, wolves, etc.)
 class Canine : public Animal {
 public:
     // Inherit constructors from Animal
     using Animal::Animal;
     
     // Default constructor with Canine-specific initialization
     Canine() : Animal() 
     {
         cout << "I am a canine!!" << endl;
     }
     
     // Override makeNoise method for Canine-specific sound
     void makeNoise() override
     {
         // Base implementation left empty
         // Specific sounds implemented in derived classes
     }
     
     // Override eat method for Canine-specific eating habits
     void eat() override 
     {
         // Check if verbose messaging is enabled
         if(Animal::suppressExtraMessages)
         {
             // Condensed output for suppressed mode
             cout << "From C: I am a nice canine you know. I eat whatever you feed me." << endl;
             cout << "But please please don't serve that pedigree!!" << endl;
         }
         else
         {
             // Full output for normal mode
             cout << "From C: I am a nice canine you know. I eat whatever you feed me." << endl;
             cout << "But please please don't serve that pedigree!!" << endl;
             cout << "I only like my meals fresh, if I am being honest." << endl;
         }
     }
     
     // Override roam method for Canine-specific roaming behavior
     void roam() override 
     {
         // Call base class implementation first
         Animal::roam();
         
         // Only add additional messages if not suppressed
         if(!Animal::suppressExtraMessages)
         {
             cout << "From C: I like to roam in a group. You are welcome to be part of my group" << endl;
         }
     }
 };
 
 #endif // CANINE_H