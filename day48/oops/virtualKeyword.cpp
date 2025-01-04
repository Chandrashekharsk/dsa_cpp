#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    void makeSound() { 
        cout << "Generic animal sound" << endl; 
    } 
};

class Dog : public Animal {
public:
    void makeSound() { // Overriding the virtual function
        cout << "Woof!" << endl; 
    }
};


class Animal1 {
public:
    virtual void makeSound() { 
        cout << "Generic animal sound" << endl; 
    } 
};

class Dog1 : public Animal1 {
public:
    void makeSound() override { // Overriding the virtual function
        cout << "Woof!" << endl; 
    }
};

int main(){

  Dog d1;
  d1.makeSound();
  Animal a1;
  a1.makeSound();

  Animal* animalPtr = &d1; // Base class pointer pointing to derived class object
  animalPtr->makeSound(); // Calls Animal's makeSound() due to static binding
  // to fix this issue we use virtual keyword
// <----------------------------------------------------------------->

  cout<<"<---------------------------------------------->"<<endl;
  Dog1 d2;
  d2.makeSound();
  Animal1 a2;
  a2.makeSound();

  Animal1* animalPtr2 = &d2; // Base class pointer pointing to derived class object
  animalPtr2->makeSound(); // Calls Animal's makeSound() due to static binding
  // to fix this issue we use virtual keyword

  return 0;
}