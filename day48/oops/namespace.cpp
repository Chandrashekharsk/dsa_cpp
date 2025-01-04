#include <iostream>
#include <vector>
using namespace std;

// Defining a Namespace
namespace MyNamespace {
// Declarations of variables, functions, classes, etc.
  int x;
  void myFunction() {
    // ...
  }
  class MyClass {
    // ...
  };
} 




namespace Geometry {
  double pi = 3.14159;
  double calculateArea(double radius) { 
    return pi * radius * radius; 
  }
}

int main() {

  // Accessing Namespace Members
  MyNamespace::x = 10;
  MyNamespace::myFunction();
  MyNamespace::MyClass obj;

  // Using a using Declaration
  using MyNamespace::x; 
  using MyNamespace::myFunction; 
  // Now you can use x and myFunction without the namespace prefix

  // Using a using Directive
  using namespace MyNamespace; 
  // All members of MyNamespace are now accessible directly


    double area = Geometry::calculateArea(5.0); 
    cout << "Area of the circle: " << area << endl; 
    return 0;

  return 0;
}