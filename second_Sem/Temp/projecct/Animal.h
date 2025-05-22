/**
 * Animal.h
 * 
 * PSEUDOCODE:
 * 1. Define Animal class as the base class for all animals
 * 2. Declare private attributes: picture, food, hunger, boundaries
 * 3. Declare protected static flag for controlling verbose output
 * 4. Declare public constructors: default, parameterized, copy
 * 5. Declare virtual destructor
 * 6. Declare getters and setters for all attributes
 * 7. Declare virtual methods: makeNoise, eat, roam
 * 8. Declare final methods: sleep, print
 * 9. Declare friend operator<< for output streaming
 */

 #ifndef ANIMAL_H
 #define ANIMAL_H
 
 #include <iostream>
 #include <string>
 using namespace std;
 
 class Animal
 {
     private:
     // Core attributes of all animals
     string animalPicture;    // Visual representation of animal
     string animalFood;       // Preferred food type 
     int hungerLevel;         // Hunger intensity (1-10 scale)
     string habitatBoundaries; // Natural habitat limits
     
     protected:
     // Control flag for verbose messaging
     static bool suppressExtraMessages;
     
     public:
     // Constructors
     Animal();  // Default constructor
     Animal(const string& pic, const string& f, int hungry, const string& bound);  // Parameterized constructor
     Animal(const Animal& other);  // Copy constructor
     
     // Virtual destructor for proper inheritance cleanup
     virtual ~Animal(){}
 
     // Static method to control message verbosity
     static void setSuppressExtraMessages(bool suppress)
     {
         suppressExtraMessages = suppress;
     }
     
     // Setter methods
     void setPicture(const string& pic); 
     void setFood(const string& f);
     void setHunger(int hungry);
     void setBoundaries(const string& bound);
     
     // Getter methods
     string getPicture() const;
     string getFood() const;
     int getHunger() const;
     string getBoundaries() const;
     
     // Virtual behavior methods
     virtual void makeNoise();  // To be defined by derived classes
     virtual void eat();        // Can be overridden by derived classes
     virtual void sleep() final; // Cannot be overridden by derived classes
     virtual void roam();       // Can be overridden by derived classes
     virtual void print() final; // Cannot be overridden by derived classes
     
     // Friend function for streaming output
     friend ostream& operator<<(ostream& os, const Animal& animal);
 };
 
 #endif // ANIMAL_H