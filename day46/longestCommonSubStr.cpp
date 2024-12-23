// Longest common sub string
#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2){
  vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, 0));
  for (int j=0; j<=s1.size(); j++) dp[0][j] = 0;
  for (int i=0; i<=s1.size(); i++) dp[i][0] = 0;


  int maxi = -1e9;
  for(int i=1; i<=s1.size(); i++){
    for (int j=1; j<=s2.size(); j++){
      if(s1[i-1] == s2[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        maxi = max(maxi, dp[i][j]);

      } else dp[i][j] = 0;
    }
  }
  return maxi;
}

int lcs2(string s1, string s2){
  vector<int> prev (s2.size()+1, 0), curr  (s2.size()+1, 0);

  for (int j=0; j<=s1.size(); j++) prev[j] = curr[j]= 0;


  int maxi = -1e9;
  for(int i=1; i<=s1.size(); i++){
    for (int j=1; j<=s2.size(); j++){
      if(s1[i-1] == s2[j-1]){
        curr[j] = 1 + prev[j-1];
        maxi = max(maxi, curr[j]);

      } else curr[j] = 0;
    }
    prev = curr;
  }
  return maxi;
}

int main(){

  string s1 = "abcd";
  string s2 = "abzd";
  cout<<lcs(s1, s2)<<"\n";
  cout<<lcs2(s1, s2)<<"\n";

  return 0;
}