#include <iostream>
using namespace std;

int main() {
  // int x = 10;       // Regular integer variable
  // int* ptr = &x;    // Pointer storing the address of x

  // cout << "Value of x: " << x << endl;       // 10
  // cout << "Address of x: " << &x << endl;    // Memory address of x
  // cout << "Value of ptr: " << ptr << endl;   // Same as &x
  // cout << "Value pointed to by ptr: " << *ptr << endl; // Dereferencing ptr
  // to get x's value

  int* ptr = new int;  // Allocates memory for a single integer
  *ptr = 42;
  cout << *ptr<<"\n";  // 42
  cout << ptr;  // 42
  delete ptr;    // Frees the memory

  return 0;
}
