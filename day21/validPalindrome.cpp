// 125.Valid Palindrome
#include<iostream>
#include<vector>
using namespace std;

bool isAlNum(char ch){
  if(ch >='0' && ch<='9' || tolower(ch)>='a' && tolower(ch)<='z') return false;
  return true;
}

bool validPalindrome(string s){
  int st = 0, end = s.length()-1;
  while(st<end){
    while(isAlNum(s[st])) st++;
    while(isAlNum(s[end]))  end--;

    if(tolower(s[st]) != tolower(s[end])) return false;
    st++; end--;
  }
  return true;
}

int main(){

  // string str = "heelo";
  string str = "racecar";
  cout<<validPalindrome(str)<<"\n";


  return 0;
}