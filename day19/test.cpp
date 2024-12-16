#include <iostream>
#include <vector>
using namespace std;

int main()
{

  int a = 5;
  int* tail = nullptr;

  int *ptr1 = &a;
  cout<< ptr1;
  cout << ptr1 << "\n";
  int* ptr2 = ptr1;
  tail = ptr1;
  cout<< ptr2<<" "<< ptr1;

  return 0;
}