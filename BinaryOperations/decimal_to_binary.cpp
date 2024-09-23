// convert decimal number to binary number 

#include<iostream>
using namespace std;

int decimalToBinary(int n){

  int ans = 0;
  int pow = 1;

  while(n>0){
    int rem = n%2;
    n = n/2;
    ans += rem * pow;
    pow = pow * 10;
  }
  return ans;
}

int main(){

  // cout<< "Enter number: "; int n; cin>>n;
  for(int i=1; i<=10; i++){
  cout<<i<<" : "<<decimalToBinary(i)<<"\n";
  }
  // cout<<decimalToBinary(n);

  return 0;
}