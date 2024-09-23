// covert a binary to decimal number 

#include<iostream>
using namespace std;

int binaryToDecimal(int n){
  int ans = 0; int pow = 1;
  while(n>0){
    int rem = n%10;
    n = n/10;
    ans += rem * pow;
    pow = pow * 2;
  }

  return ans;
}

int main(){

  cout<<"Enter binary number: "; int n; cin>>n;
  cout<< binaryToDecimal(n);

  return 0;
}