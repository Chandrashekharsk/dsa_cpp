// 567.Permutation in String
#include<iostream>
#include<vector>
using namespace std;

bool isMatch(vector<int> freq, vector<int> windowFreq){
  for(int i=0; i<26; ++i){
    if(freq[i] != windowFreq[i]) return false;
  }
  return true;
}

bool checkInclusion(string s1, string s2) {
  vector<int> freq(26,0);  // size, initalValue
  for(int i=0; i<s1.length(); ++i) freq[s1[i]-'a']++;

  for(int i=0; i<s2.length(); ++i){
    int windowIdx = 0, strIdx = i;
    vector<int> windowFreq(26,0);  // size, initalValue

    // windowSize -> s1.legth()
    while(windowIdx<s1.length() && strIdx<s2.length()){
      windowFreq[s2[strIdx] - 'a']++;
      windowIdx++; strIdx++;
    }
    // if(isMatch(freq, windowFreq)) return true;
    if(freq == windowFreq) return true;
  }
  return false;
}

int main(){
  string s1 = "ab", s2 = "eidbaooo";
  // string s1 = "ab", s2 = "eidboaoo";
  cout << checkInclusion(s1, s2);

  return 0;
}