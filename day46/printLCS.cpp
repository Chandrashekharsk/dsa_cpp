#include <iostream>
#include <vector>
using namespace std;


int helper2(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (i == 0 || j == 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i - 1] == s2[j - 1])
    return dp[i][j] = 1 + helper2(i - 1, j - 1, s1, s2, dp);
  return dp[i][j] = max(helper2(i - 1, j, s1, s2, dp), helper2(i, j - 1, s1, s2, dp));
}

int lcs2(string s1, string s2) {
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  return helper2(s1.size(), s2.size(), s1, s2, dp);
}

int lcs3(string s1, string s2) {
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
  for (int j = 0; j <= s2.size(); j++) dp[0][j] = 0;
  for (int i = 0; i <= s1.size(); i++) dp[i][0] = 0;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  
  for(int i=0; i<=s1.size(); i++){
    for (int j=0;j<=s2.size(); j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  string ansStr = "";
  int i=s1.size(), j= s2.size();
  while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
      ansStr = s1[i-1] + ansStr;
      i--; j--;
    }else {
      if(dp[i-1][j]>dp[i][j-1]){
        i--;
      }else{
        j--;
      }
    }
  }
  cout<<ansStr<<"\n";

  return dp[s1.size()][s2.size()];
}


int main() {
  string s1 = "abcde";
  string s2 = "bdgek";

  // cout << lcs2(s1, s2) << "\n";
  cout << lcs3(s1, s2) << "\n";

  return 0;
}