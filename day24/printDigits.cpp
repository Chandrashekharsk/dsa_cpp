#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void printDigits(int n){
  int count = 0;
  while(n != 0){
    int lastDigit = n%10;
    count++;
    cout<<lastDigit<<" ";
    n/=10;
  }
  cout<<"\ncount: "<<count;
}

int main(){
  int n = 3586;
  printDigits(n); cout<<"\n";

  // shortcut for count digits present in number
  cout<<"sortcut result: "<<(int) (log10(n)+1)<<"\n";

  return 0;
}