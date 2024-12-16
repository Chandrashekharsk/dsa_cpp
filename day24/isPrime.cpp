#include<iostream>
#include<vector>
using namespace std;

int isPrime(int n){
  if(n<2) return -1;
  for(int i=2; i*i<=n; i++){
    if(n%i == 0) return false;
  }
  return true;
}

int main(){

  // if(isPrime(17)){
  //   cout<<"Prime number";
  // } 
  if(isPrime(2)){
    cout<<"Prime number";
  } 
  else cout<<"Non Prime number";


  return 0;
}