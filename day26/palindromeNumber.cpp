// 9.Palindrome Number 
#include<iostream>
#include<vector>
using namespace std;

int reverseInteger(int x){
  int ans = 0;

  while(x != 0){
    int lastDigit = x%10;

    //check for integer overflow
    if(ans> INT_MAX/10 || ans == INT_MAX/10 && lastDigit > INT_MAX%10) return 0;
    if(ans< INT_MIN/10 || ans == INT_MIN/10 && lastDigit< INT_MIN%10) return 0;

    ans = (ans*10) + lastDigit;
    x/=10;
  }
  return ans;
}


bool isPalindrome(int x){
  if(x<0) return false;
  int reverseNumber = reverseInteger(x);
  return reverseNumber == x;
}


int main(){

  cout<<isPalindrome(567)<<"\n";
  cout<<isPalindrome(565)<<"\n";
  cout<<isPalindrome(-565)<<"\n";


  return 0;
}