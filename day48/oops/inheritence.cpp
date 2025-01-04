#include <iostream>
#include <string>
using namespace std;

class Animal {
  protected:
    string name;

  protected:
    void setName(const string& animalName) { 
      name = animalName;
    }
    string getName() const { 
      return name;
    }
};

class Dog : public Animal {
  public:
  void displayInfo() {
    setName("Buddy");  // Accessing protected member
    cout << "Dog's name is: " << getName() << endl;
  }
};

int main() {
  Dog myDog;
  myDog.displayInfo();
  return 0;
}