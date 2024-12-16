#include<iostream>
using namespace std;


int main(){
  int n;
  cout<< "Enter you number: "; cin>>n;

  // FOR loop for calculate sum of all ODD numbers till 1-N
  int i=1;
  int oddSum = 0;
  for(; i<=n;i++){
    if(n%2 != 0) oddSum+=i;
  }
  cout<<oddSum<<"\n";

  // WHILE loop for calculate sum of all EVEN numbers till 1-N
  int j=1;
  int evenSum = 0;
  while(j<=n) {
    j%2 ==0? evenSum +=j:0; 
    j++;
  }
  cout<<evenSum;

  return 0;
}