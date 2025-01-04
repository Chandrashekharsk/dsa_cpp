#include <iostream>
using namespace std;

class Base {
 public:
  void display() {  // Non-virtual function
    cout << "Display from Base class" << endl;
  }
};

class Derived : public Base {
 public:
  void display() {  // Hides Base's display()
    cout << "Display from Derived class" << endl;
  }
};

int main() {
  Base baseObj;
  Derived derivedObj;

  baseObj.display();     // Calls Base's display()
  derivedObj.display();  // Calls Derived's display()

  Base* basePtr = &derivedObj;
  basePtr->display();  // Calls Base's display() due to static binding

  return 0;
}
