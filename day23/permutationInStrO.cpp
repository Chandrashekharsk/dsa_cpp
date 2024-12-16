#include<iostream>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2){
  if(s1.length()> s2.length()) return false;
  vector<int> freq(26,0), windowFreq(26,0);

 // Frequency count for s1 along with Initial window in s2
  for(int i=0; i<s1.length(); ++i){
    freq[s1[i]-'a']++;
    windowFreq[s2[i]-'a']++;
  }

   // Check the initial window
  if (freq == windowFreq) return true;

  // Slide the window over s2
  for (int i = s1.length(); i < s2.length(); ++i) {
    windowFreq[s2[i] - 'a']++;                   // Add new character to the window
    windowFreq[s2[i - s1.length()] - 'a']--;      // Remove old character from the window

    if (freq == windowFreq) return true;          // Check if the updated window matches
  }
  return false;
}

int main(){

  // string s1 = "ab", s2 = "eidbaooo";
  string s1 = "ab", s2 = "eidboaoo";
  cout << checkInclusion(s1, s2);
  return 0;
}