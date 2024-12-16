// int a = 5;   //
// int* ptr = &a;   // add of a
// valOfA = *ptr;   // 5 de-reference
// int** ptr2 = &ptr;   // add of ptr

#include<iostream>
using namespace std;

// pass by reference using POINTER
// int changeA(int* ptr){
//   *ptr = 20;
// }

// pass by reference using ALIAS
int changeA(int &n){
  n = 20;
}

int main(){
  int a = 10;
  // changeA(&a);
  changeA(a);
  
  cout<< a<<" ";
  return 0;
}