#include<iostream>
#include<vector>
using namespace std;

//1: Accessing Static Members of a Class
// class MyClass {
// public:
//     static int count;  // Declaration of static member
// };

// int MyClass::count = 0;  // Definition of static member using ::


//2: Defining Member Functions Outside the Class
// class MyClass {
// public:
//     void display();
// };

// void MyClass::display() {  // Use :: to define the function
//     cout << "Hello, World!" << endl;
// }

//3: Accessing Global Variables When Shadowed by Local Variables
// int x = 10;  // Global variable

// void example() {
//     int x = 20;  // Local variable
//     cout << ::x << endl;  // Access global x using ::
// }


//4:Accessing Namespaces
// namespace MyNamespace {
//     void display() {
//         cout << "Inside MyNamespace" << endl;
//     }
// }

// int main() {
//     MyNamespace::display();  // Access display() inside MyNamespace
//     return 0;
// }

//5: Resolving Ambiguity in Multiple Inheritances
class A {
public:
    void display() { 
      cout << "Class A" << endl;
    }
};

class B {
public:
    void display() { 
      cout << "Class B" << endl; 
    }
};

class C : public A, public B {
public:
    void show() {
        A::display();  // Use :: to specify Class A's display
        B::display();  // Use :: to specify Class B's display
    }
};





int main(){
  C c1;
  c1.show(); // first A's display run and then B's display run


  return 0;
}