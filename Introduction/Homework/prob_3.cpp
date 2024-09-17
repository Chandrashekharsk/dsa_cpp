// Calculate Factorial of a number N.

#include<iostream>
using namespace std;

int calculateFactorial(int n){
  if (n==1 || n==0) return 1;
  return n* calculateFactorial(n-1);
}

int main(){
  int n;
  cout<<"Enter number: "; cin>>n;
  cout<<calculateFactorial(n);

  return 0;
}

