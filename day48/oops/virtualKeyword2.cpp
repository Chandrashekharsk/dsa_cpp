#include <iostream>
using namespace std;

class Base {
 public:
  virtual void display() {  // Virtual function
    cout << "Display from Base class" << endl;
  }
};

class Derived : public Base {
 public:
  void display() override {  // Override base class function
    cout << "Display from Derived class" << endl;
  }
};

int main() {
  Base* basePtr;
  Derived derivedObj;

  basePtr = &derivedObj;
  basePtr->display();  // Calls Derived's display() due to polymorphism

  return 0;
}
