/**
 * Feline.h
 * 
 * PSEUDOCODE:
 * 1. Define Feline class inheriting from Animal
 * 2. Inherit all constructors from Animal
 * 3. Override default constructor with Feline-specific behavior
 * 4. Override virtual methods: makeNoise, eat, roam
 * 5. Implement Feline-specific behaviors and characteristics
 */

 #ifndef FELINE_H
 #define FELINE_H
 
 #include "Animal.h"
 #include <iostream>
 using namespace std;
 
 // Feline class - represents all feline animals (lions, tigers, etc.)
 class Feline: public Animal
 {
     public:
     // Inherit constructors from Animal
     using Animal::Animal;
     
     // Default constructor with Feline-specific initialization
     Feline(): Animal()
     {
         cout << "I am a Feline!!" << endl;
     }
     
     // Override makeNoise method for Feline-specific sound
     void makeNoise() override
     {
         cout << "From F: I make a scary noise" << endl;
     }
     
     // Override eat method for Feline-specific eating habits
     void eat() override
     {
         cout << "From F: I am a nice Feline you know." << endl;
         cout << "I eat whatever I see and that means YOU! Haha!!" << endl;
     }
     
     // Override roam method for Feline-specific roaming behavior
     void roam() override
     {
         // Call base class implementation first
         Animal::roam();
         
         // Only add additional messages if not suppressed
         if(!Animal::suppressExtraMessages)
         {
             cout << "From F: I can be a scaredy cat. I find comfort in roaming areas away from everyone" << endl;
             cout << "Do not approach me." << endl;
         }
     }
 };
 #endif // FELINE_H