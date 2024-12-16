#include<iostream>
#include<vector>
using namespace std;

  

int main(){

  string s = "helloworld";

  int hash[256] = {0};
  for(int i=0; i<s.size(); i++){
    hash[s[i]]++;
  }
  cout<< hash['l'];

  return 0;
}