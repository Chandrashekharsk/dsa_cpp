// 344.Reverse String
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(char& a, char& b){
  char temp = a; a = b; b = temp;
}
void reverseString(vector<char>& s){
  if(s.size()==1) return;
  int st = 0, end = s.size()-1; 
  while(st<end){
    swap(s[st++], s[end--]);
  }
}


int main(){
  vector<char> s = {'h', 'e', 'l', 'o', ' ', 'g', 'u', 'y', 's', '.'}; 

  // using string stl collection
  // reverse(s.begin(), s.end()); // returns iterator


  // using char vector
  reverseString(s);

  for(char ch : s) cout<< ch;

  return 0;
}