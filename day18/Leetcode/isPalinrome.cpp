// 125. Valid Palindrome
// use    isalpha()--->alphabets,   isalnum()---->alphabets & digits
#include<iostream>
#include<vector>
using namespace std;

// include check for      alphanumeric --->alphabets + digits
bool isPalindrome(string s) {
  if(s.size()<=1) return true;
  int st = 0, end = s.size()-1;
  while(st<end){
    while(st<end && !isalnum(s[st])) st++;
    while(st<end && !isalnum(s[end])) end--;
    if(tolower(s[st]) != tolower(s[end])) return false;
    st++; end--;
  }
  return true;
}

int main(){

  // string s = ".ni2:tin,";
  string s = "0P";
  // string s = "A man, a plan, a canal: Panama";
  // string s = "nitin";
  string s1 = "hello guys";
  cout<<isPalindrome(s)<<"\n";
  // cout<<isPalindrome(s1)<<"\n";


  return 0;
}