//==========================================================
// PSEUDOCODE FOR ANIMAL CLASS IMPLEMENTATION:
// 1. Implement constructors (default, parameterized, copy)
// 2. Implement getters for all attributes
// 3. Implement setters for all attributes
// 4. Implement virtual methods (eat, roam, sleep, print)
// 5. Implement operator<< for output streaming
//==========================================================

#include "Animal.h"
#include <iostream>
using namespace std;

// Default constructor - initializes an animal with default values
Animal::Animal() : picture("animal"), food("human"), hunger(1), boundaries("Jungle") {
    cout << "From Animal: Default constructor called\n";
}

// Parameterized constructor - initializes an animal with specific values
Animal::Animal(string pictureName, string foodType, int hungerLevel, string habitatBoundaries) :
    picture(pictureName), food(foodType), hunger(hungerLevel), boundaries(habitatBoundaries) {
    cout << "From Animal: Parameterized constructor called\n";
}

// Copy constructor - creates a new animal as a copy of an existing one
Animal::Animal(const Animal& other) :
    picture(other.picture), food(other.food), hunger(other.hunger), boundaries(other.boundaries) {
    cout << "From Animal: Copy constructor called\n";
}

//-------- Getter Methods --------

// Returns the picture representation of the animal
string Animal::getPicture() const {
    return picture;
}

// Returns the food type this animal eats
string Animal::getFood() const {
    return food;
}

// Returns the hunger level of the animal
int Animal::getHunger() const {
    return hunger;
}

// Returns the boundaries/habitat of the animal
string Animal::getBoundaries() const {
    return boundaries;
}

//-------- Setter Methods --------

// Sets a new picture representation for the animal
void Animal::setPicture(string pictureName) {
    picture = pictureName;
}

// Sets a new food type for the animal
void Animal::setFood(string foodType) {
    food = foodType;
}

// Sets a new hunger level for the animal
void Animal::setHunger(int hungerLevel) {
    hunger = hungerLevel;
}

// Sets new boundaries/habitat for the animal
void Animal::setBoundaries(string habitatBoundaries) {
    boundaries = habitatBoundaries;
}

//-------- Virtual Method Implementations --------

// Defines the eating behavior of the animal
void Animal::eat() {
    cout << "From Animal: I'm eating " << food << endl;
}

// Defines the roaming behavior of the animal
void Animal::roam() {
    cout << "From Animal: I'm roaming in " << boundaries << endl;
}

// Defines the sleeping behavior of the animal
void Animal::sleep() {
    cout << "From Animal: I'm sleeping\n";
}

// Prints all attributes of the animal
void Animal::print() {
    cout << "Picture: " << picture << "\nFood: " << food 
         << "\nHunger: " << hunger << "\nBoundaries: " << boundaries << endl;
}

//-------- Operator Overloading --------

// Overloads << operator to allow printing animal objects directly
ostream& operator<<(ostream& output, const Animal& animal) {
    output << "Picture: " << animal.getPicture() 
           << "\nFood: " << animal.getFood()
           << "\nHunger: " << animal.getHunger()
           << "\nBoundaries: " << animal.getBoundaries();
    return output;
}