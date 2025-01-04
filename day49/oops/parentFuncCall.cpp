#include <iostream>
using namespace std;

class Parent {
 public:
  void greet() { cout << "Hello from Parent!" << endl; }
};

class Child : public Parent {
 public:
  void greet() {
    cout << "Hello from Child!" << endl;
    Parent::greet();  // Call the parent class method
  }
};

// Usage
int main() {
  Child child;
  child.greet();
  return 0;
}
