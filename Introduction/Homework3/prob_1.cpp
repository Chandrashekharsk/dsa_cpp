// Sum of all numbers form 1 o N which are divisible by 3.

#include<iostream>
using namespace std;

int main(){

  cout<< "Enter value of range: "; int n; cin >> n;
  int sum=0;
  for(int i=1; i<=n; i++){
    if(i%3 == 0) {
     sum+=i;
    }
  }
  cout<< "Sum: "<< sum;

  return 0;
}