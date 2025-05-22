/**
 * Animal.cpp
 * 
 * PSEUDOCODE:
 * 1. Initialize static member variable
 * 2. Implement all constructors with appropriate messages
 * 3. Implement getters and setters for all attributes
 * 4. Implement virtual methods with base behaviors
 * 5. Implement final methods: sleep and print
 * 6. Implement stream operator overload
 */

 #include "Animal.h"

 // Initialize static member - defaults to not suppressing messages
 bool Animal::suppressExtraMessages = false;
 
 // Default constructor - sets default values
 Animal::Animal() : animalPicture("animal"), animalFood("human"), hungerLevel(1), 
 habitatBoundaries("Jungle") {
     cout << "I am part of my animal kingdom. Welcome!!" << endl;
 }
 
 // Parameterized constructor - initializes with provided values
 Animal::Animal(const string& pic, const string& f, int hungry, 
 const string& bound): animalPicture(pic), animalFood(f),
 hungerLevel(hungry), habitatBoundaries(bound) {
     // Comment out for cleaner output in main
     //cout << "I am part of my animal kingdom with all parameters set!!" << endl;
 }
 
 // Copy constructor - copies values from another Animal object
 Animal::Animal(const Animal& other): animalPicture(other.animalPicture), 
 animalFood(other.animalFood), hungerLevel(other.hungerLevel), 
 habitatBoundaries(other.habitatBoundaries) {
     cout << "My job is to copy" << endl;
 }
 
 // Setter implementations
 void Animal::setPicture(const string& pic) { animalPicture = pic; }
 void Animal::setFood(const string& f) { animalFood = f; }
 void Animal::setHunger(int hungry) { hungerLevel = hungry; }
 void Animal::setBoundaries(const string& bound) { habitatBoundaries = bound; }
  
 // Getter implementations
 string Animal::getPicture() const { return animalPicture; }
 string Animal::getFood() const { return animalFood; }
 int Animal::getHunger() const { return hungerLevel; }
 string Animal::getBoundaries() const { return habitatBoundaries; }
 
 // Virtual method implementations
 void Animal::eat() {
     cout << "From A: I am extremely friendly! I will eat anything I am given!!" << endl;
 }
 
 void Animal::makeNoise() {
     // Base implementation left empty intentionally
     // Could be made pure virtual if needed
 }
 
 // Final method implementations
 void Animal::sleep() {
     cout << "From A: ZZZZ I am sleeping. Don't disturb me." << endl;
     cout << "I can get wild if you disturb me during my sleep!!" << endl;
 }
 
 void Animal::roam() {
     cout << "From A: I like to roam in forest. But the humans destroyed my habitat" << endl;
 }
 
 // Print method - shows all attributes
 void Animal::print() {
     cout << "Picture: " << animalPicture << endl;
     cout << "Food: " << animalFood << endl;
     cout << "Hunger Level: " << hungerLevel << endl;
     cout << "Boundaries: " << habitatBoundaries << endl;
 }
 
 // Stream operator overload for easy printing
 ostream& operator<<(ostream& os, const Animal& animal) {
     os << "Picture: " << animal.getPicture() << endl;
     os << "Food: " << animal.getFood() << endl;
     os << "Hunger Level: " << animal.getHunger() << endl;
     os << "Boundaries: " << animal.getBoundaries() << endl;
     return os;
 }