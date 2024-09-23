// calculate sum of all digits of a number
// FORMULA:  last_digit(remainder)= number%10,  remove_last_digit(quotient)= number/10

#include<iostream>
using namespace std;

int calculate_digits_Sum(int n){
  int sum = 0;
  while(n>0){
    int last_digit = n%10;  // get last digit
    sum+= last_digit;
    n = n/10;               // remove last digit
  }
  return sum;
}

int main(){
  cout<<"Enter number to calculate sum: "; int n; cin>> n;
  cout<<calculate_digits_Sum(n);
  return 0;
}
