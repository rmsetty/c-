/**
 * main.cpp
 * 
 * PSEUDOCODE:
 * 1. Include all necessary header files
 * 2. Test Rhinos class with various constructors and methods
 * 3. Test Lion class
 * 4. Test Wolf class with various constructors
 * 5. Demonstrate static binding with array of Animal objects
 * 6. Demonstrate dynamic binding with array of Animal pointers
 * 7. Test Vet class with different animal types
 * 8. Clean up memory for dynamically allocated objects
 */

 #include <iostream>
 #include "Rhinos.h"
 #include "Lion.h"
 #include "Tiger.h"
 #include "Wolf.h"
 #include "Dog.h"
 #include "Vet.h"
 using namespace std;
 
 int main()
 {
	 // PART 1: Test Rhinos class with parameterized constructor
	 Rhinos rhinoWithParams("Rhino", "Grass", 2, "Jungle");
	 cout << rhinoWithParams; // Test stream operator
	 cout << endl << endl;
	 
	 // Test virtual methods
	 rhinoWithParams.makeNoise();
	 rhinoWithParams.eat();
	 rhinoWithParams.roam();
	 rhinoWithParams.sleep();
	 cout << "The food I eat is " << rhinoWithParams.getFood() << endl << endl;
 
	 // Test Rhinos with default constructor
	 cout << "\nRhinos with no parameters \n";
	 Rhinos rhinoDefault;
	 cout << rhinoDefault;
	 rhinoDefault.makeNoise();
	 rhinoDefault.eat();
	 rhinoDefault.roam();
	 rhinoDefault.sleep();
	 cout << "The food I eat is " << rhinoDefault.getFood() << endl << endl;
 
	 // Test Rhinos with copy constructor
	 cout << "\nNew Rhino: \n";
	 Rhinos rhinoCopy(rhinoDefault);
	 cout << rhinoCopy;
	 cout << endl;
 
	 // PART 2: Test Lion class
	 cout << "\nLION \n";
	 Lion lionObject;
	 cout << lionObject;
	 cout << endl << endl;
	 lionObject.makeNoise();
	 lionObject.eat();
	 lionObject.roam();
	 lionObject.sleep();
	 cout << endl << endl;
 
	 // PART 3: Test Wolf class with parameters
	 cout << "\nWOLF \n";
	 Wolf wolfWithParams("Wolfe", "Meat", 10, "Fields");
	 cout << wolfWithParams;
	 cout << endl << endl;
	 wolfWithParams.makeNoise();
	 wolfWithParams.eat();
	 wolfWithParams.roam();
	 wolfWithParams.sleep();
	 cout << endl << endl;
 
	 // Test Wolf with assignment operator
	 wolfWithParams.setFood("Rabbit");
	 cout << "\nCopying another WOLF object\n";
	 Wolf wolfCopy = wolfWithParams;
	 cout << wolfCopy;
 
	 // PART 4: Static Binding demonstration
	 // Note: If makeNoise is pure virtual, this section would cause compilation errors
	 Animal animalArray[5];
	 cout << "\nDOG:" << endl;
	 animalArray[0] = Dog("Tommy", "YogurtRice", 12, "Home");
	 cout << " \nWOLF:" << endl;
	 animalArray[1] = Wolf();
	 cout << "\nRHINOS:" << endl;
	 animalArray[2] = Rhinos();
	 cout << "\nTIGER:" << endl;
	 animalArray[3] = Tiger();
	 cout << "\nLION:" << endl;
	 animalArray[4] = Lion();
	 cout << endl;
 
	 // Test methods on static array
	 cout << ("\nEating, roaming and noise Habits:\n");
	 cout << ("----------------------------------\n");
	 for(int i = 0; i < 5; i++)
	 {
		cout << animalArray[i];
		animalArray[i].makeNoise();
		animalArray[i].eat();
		animalArray[i].roam();
		animalArray[i].sleep();
		cout << endl;
	 }
	 
	 // PART 5: Dynamic Binding demonstration
	 Animal *animalPtrArray[5];
	 cout << "Dog: \n";
	 animalPtrArray[0] = new Dog("Tommy", "YogurtRice", 12, "Home");
	 cout << endl;
	 cout << "Wolf: \n";
	 animalPtrArray[1] = new Wolf();
	 cout << endl;
	 cout << "Rhinos: \n";
	 animalPtrArray[2] = new Rhinos();
	 cout << endl;
	 cout << "Tiger: \n";
	 animalPtrArray[3] = new Tiger("Tigger", "you", 15, "Sambal Forest");
	 cout << endl;
	 cout << "Lion: \n";
	 animalPtrArray[4] = new Lion();
	 cout << endl;
 
	 // Test methods on dynamic array with suppressed messages
	 cout << ("\nEating, roaming and noise Habits:\n");
	 cout << ("----------------------------------\n");
	 Animal::setSuppressExtraMessages(true); 
	 for(int i = 0; i < 5; i++)
	 {
		 animalPtrArray[i]->print();
		 cout << endl;
		 animalPtrArray[i]->makeNoise();
		 animalPtrArray[i]->eat();
		 animalPtrArray[i]->roam();
		 animalPtrArray[i]->sleep();
		 cout << endl << endl;
	 }
	 Animal::setSuppressExtraMessages(false);
 
	 // PART 6: Testing Vet class with different animal types
	 Vet vetObject;
	 cout << "\nDOG:" << endl;
	 Dog dogObject;
	 cout << "\nVet:" << endl;
	 vetObject.giveShot(dogObject);
	 cout << "\nRhinos:" << endl;
	 Rhinos rhinoObject;
	 cout << "\nVet:" << endl;
	 vetObject.giveShot(rhinoObject);
	 cout << "\nFeline:" << endl;
	 Feline felineObject;
	 cout << "\nVet:" << endl;
	 vetObject.giveShot(felineObject);
	 cout << endl;
 
	 // Clean up dynamically allocated memory
	 for (int i = 0; i < 5; i++) {
		 delete animalPtrArray[i];
	 }
 
	 return 0;
 }	