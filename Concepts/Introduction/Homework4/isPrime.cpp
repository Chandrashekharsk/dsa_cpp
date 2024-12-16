// WAF to check if a number is prime or not

#include<iostream>
using namespace std;

bool isPrime(int n){
  if(n==1){
    return false;
  }
  bool prime = true;
  for(int i=2; i<n; i++){
    if(n%i == 0){
      prime = false;
    }
  }
  return prime;
}

int main(){

  cout<< "Enter number: ";int n; cin >> n;
  if(n<1){
    cout<<"Invalid number";
  }
  isPrime(n)?cout<<"Prime":cout<<"Not prime";
  return 0;
}