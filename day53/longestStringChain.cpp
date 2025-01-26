#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(string& s1, string& s2){
  if(s1.size()<s2.size()) return false;
  int first = 0, second = 0;

  while(first<s1.size()){
    if(s1[first] == s2[second]){
      ++first; ++second;
    }else{
      ++first;
    }
  }
  if(s1[first] == s2[second]) return true;
  return false;
};

bool comp(string& s1, string& s2){
  // if below condition true do nothing else reverse them
  return s1.size() < s2.size();
}

int lsc(vector<string>& words){
  sort(words.begin(), words.end(), comp);
  vector<int> dp(words.size(), 1);
  int maxi = 1;

  for (int i=0; i<words.size(); ++i){
    for (int prev=0; prev<i; ++prev){
      if(isPossible(words[i], words[prev]) && 1+ dp[prev]> dp[i]){
        dp[i] = 1+dp[prev];
      }
    }
    if(dp[i]>maxi) maxi = dp[i];
  }
  return maxi;
}

int main(){

  vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
  cout<<lsc(words);



  return 0;
}