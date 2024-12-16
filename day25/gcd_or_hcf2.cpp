// using Euclid's Algorithm
#include<iostream>
#include<vector>
using namespace std;


int gcd(int a, int b){
  if(a==b) return a;
  while(a>0 && b>0){
    if(a>b) a%=b;
    else b%=a;
  }

  if(a==0) return b;
  return a;
}

// here we assume a is greater and b is lower initially
int gcdUsingRecursion(int a, int b){
  if(b==0) return a;
  
  return gcdUsingRecursion(b, a%b);
}

int main(){
cout<<gcd(0,12)<<"\n";
cout<<gcd(12,12)<<"\n";
cout<<gcd(12,42)<<"\n";

cout<<gcdUsingRecursion(0,12)<<"\n";
cout<<gcdUsingRecursion(12,12)<<"\n";
cout<<gcdUsingRecursion(12,42)<<"\n";

  return 0;
}