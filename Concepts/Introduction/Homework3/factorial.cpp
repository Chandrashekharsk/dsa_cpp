// Print Factorial of a number N.
// long long : very large whole number

#include<iostream>
using namespace std;

long long factorial(int n){
  long long fac = 1;
  for(int i=2; i<=n; i++){
    fac*=i;
  }
  return fac;
}

int main(){

  cout<< "Enter range: "; int n; cin>> n;
  cout<< factorial(n);
  return 0;
}