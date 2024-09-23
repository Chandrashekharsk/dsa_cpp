// calculate nCr binomial coefficient for n & r
// FORMULA:                  n!
//               nCr =  --------------
//                       r! * (n-r)!  

#include<iostream>
using namespace std;

long long factorial(int n){
  int fact = 1;
  for(int i=1; i<=n; i++){
    fact *= i;
  }
  return fact;
}

int nCr(int n, int r){
  return factorial(n) / factorial(r)*factorial(n-r);
}

int main(){
  cout<< "Enter vaue of n: "; int n; cin>> n;
  cout<< "Enter vaue of r: "; int r; cin>> r;
  cout<< nCr(n,r);
  return 0;
}