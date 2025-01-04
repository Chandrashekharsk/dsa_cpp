#include <iostream>
using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void swap2(int* a, int* b) {
  int temp = *a;  // Dereference the pointer to get the value
  *a = *b;        // Assign the value pointed by b to a
  *b = temp;      // Assign the temp value to b
}

void swap3(int& a, int& b) {
  int temp = move(a);
  a = move(b);
  b = move(temp);
}

string printMe(){
  return "I am print func";
}

int main() {
  int a = 5, b = 10;

  // Swap using references
  swap(a, b);
  cout << "After swap using references: " << a << " " << b << endl;

  // Swap using pointers
  swap2(&a, &b);
  cout << "After swap using pointers: " << a << " " << b << endl;

  // Swap using move semantics
  swap3(a, b);
  cout << "After swap using move semantics: " << a << " " << b << endl;

  string s = printMe();
  string&& ss = printMe();

  return 0;
}
