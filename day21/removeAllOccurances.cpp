// 1910.Remove All Occurrences of a Substring
// prerequisites:
// 1. myStr.find("hello"); #this will return first occurance start idx;
// 2. myStr.erase(startIdx, size);

#include<iostream>
#include<vector>
using namespace std;


string removeOccurrences(string s, string part){
  while(s.length()>0 && s.find(part)<s.length()){
    s.erase(s.find(part) ,part.length());
  }
  return s;
}

int main(){
  string s = "daabcbaabcbc", part = "abc";
  cout<<removeOccurrences(s,part);
  
  return 0;
}