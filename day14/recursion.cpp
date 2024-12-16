#include<iostream>
#include<vector>
using namespace std;

int fibbonacciTerm(int n){
  if(n<=1){
    return n;
  }
  return fibbonacciTerm(n-1) + fibbonacciTerm(n-2);
}

int main(){

  cout<< fibbonacciTerm(4);

  return 0;
}