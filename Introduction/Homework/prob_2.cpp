// Write a function maxOfTwoNumbers that takes two integers, a and b, as input and returns the maximum of the two. You are not allowed to use the built-in max() function. Instead, implement the logic using basic comparison operations.

#include<iostream>
using namespace std;

int findMax(int a, int b){
  if(a<b) return b;
  return a;
}

int main(){
  int n1, n2;
  cout << "Enter first number: "; cin>> n1;
  cout << "Enter second number: "; cin>> n2;
  cout<< findMax(n1,n2);

  return 0;
}