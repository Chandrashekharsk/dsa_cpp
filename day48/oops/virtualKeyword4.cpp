#include <iostream>
using namespace std;

class Base {
 public:
  void display() { cout << "Display from Base class" << endl; }
};

class Derived : public Base {
 public:
  void display() {
    cout << "Display from Derived class" << endl;
    Base::display();  // Call Base's display()
  }
};

int main() {
  Derived derivedObj;
  derivedObj.display();

  return 0;
}
