// GCD - Greatest/largest Common Divisor
// GCD - Highest Common factor
// (both of above means to find common greatest which divides all all given numbers);
#include<iostream>
#include<vector>
using namespace std;

int findGCD(int a, int b){
  if(a == 0 && b==0) return -1;
  if(a == b) return a;
  if(a == 0 || b==0) return max(a,b);

  int gcd = 1;
  for(int i=1; i<min(a,b); i++){
    if(a%i == 0 && b%i == 0) gcd=i;
  }
  return gcd;
}

int main(){

  cout<< findGCD(14, 16)<<"\n";
  cout<< findGCD(0, 12)<<"\n";
  cout<< findGCD(0, 0)<<"\n";

  return 0;
}