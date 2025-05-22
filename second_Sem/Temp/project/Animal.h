//==========================================================
// PSEUDOCODE FOR ANIMAL CLASS HEADER:
// 1. Define protected attributes (picture, food, hunger, boundaries)
// 2. Define constructors and virtual destructor 
// 3. Define getters and setters for all attributes
// 4. Define pure virtual function (makeNoise)
// 5. Define regular virtual methods (eat, roam, sleep, print)
// 6. Define friend operator for output streaming
//==========================================================

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

// Abstract base class for all animal types
class Animal {
protected:
    // Core attributes that all animals have
    string picture;    // Representation of the animal
    string food;       // What the animal eats
    int hunger;        // Hunger level (higher = more hungry)
    string boundaries; // Habitat/area where the animal lives

public:
    //-------- Constructors and Destructor --------
    
    // Default constructor - creates an animal with default values
    Animal();
    
    // Parameterized constructor - creates an animal with specific values
    Animal(string pictureName, string foodType, int hungerLevel, string habitatBoundaries);
    
    // Copy constructor - creates a new animal as a copy of an existing one
    Animal(const Animal& other);

    // Virtual destructor - essential for proper inheritance cleanup
    virtual ~Animal() = default;
    
    //-------- Getter Methods --------
    
    // Returns the picture representation of the animal
    string getPicture() const;
    
    // Returns the food type this animal eats
    string getFood() const;
    
    // Returns the hunger level of the animal
    int getHunger() const;
    
    // Returns the boundaries/habitat of the animal
    string getBoundaries() const;
    
    //-------- Setter Methods --------
    
    // Sets a new picture representation for the animal
    void setPicture(string pictureName);
    
    // Sets a new food type for the animal
    void setFood(string foodType);
    
    // Sets a new hunger level for the animal
    void setHunger(int hungerLevel);
    
    // Sets new boundaries/habitat for the animal
    void setBoundaries(string habitatBoundaries);

    //-------- Virtual Methods --------
    
    // Pure virtual function - must be implemented by all derived classes
    // Defines how the animal makes noise (sounds)
    virtual void makeNoise() = 0;
    
    // Virtual methods with default implementations that can be overridden
    virtual void eat();    // Defines eating behavior
    virtual void roam();   // Defines movement behavior
    virtual void sleep();  // Defines sleeping behavior
    virtual void print();  // Prints animal information

    //-------- Friend Functions --------
    
    // Allows direct streaming of animal objects using std::cout
    friend ostream& operator<<(ostream& output, const Animal& animal);
};

#endif