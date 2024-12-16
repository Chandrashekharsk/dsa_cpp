// WAF to print nth fibonacci

#include<iostream>
using namespace std;

int getFibonacciTerm(int n){
  if(n<=0) return 0;
  if(n==2 || n==1  ) return 1; return getFibonacciTerm(n-1) + getFibonacciTerm(n-2);
}


int main(){
  cout<<"Enter term number: "; int n; cin>>n;
  cout<< getFibonacciTerm(n);

  return 0;
}