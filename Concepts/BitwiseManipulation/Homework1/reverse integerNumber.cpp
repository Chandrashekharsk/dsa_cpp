// WAF to reverse an integer n

#include<iostream>
using namespace std;

int main(){

  cout<<"Enter number which need to reverse: "; int n; cin>>n;
  int ans = 0;

  while(n>0){
    int rem = n%10;
    ans = ans * 10 + rem ;
    n /= 10;
  }
  cout<< ans;
  return 0;
}