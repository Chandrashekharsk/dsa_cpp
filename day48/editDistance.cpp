// Minimum count of operations(insertion/deletion/replacement) to make string 1
// equal to string2
#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (i < 0) return j + 1;
  if (j < 0) return i + 1;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i] == s2[j]) return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
  // 1 + min(insertion, min(deletion, replacement)
  else return dp[i][j] = 1 + min(helper(i, j - 1, s1, s2, dp), min(helper(i - 1, j, s1, s2, dp), helper(i - 1, j - 1, s1, s2, dp)));
}

int editDistance(string s1, string s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  return helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
}

int helper2(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (i == 0) return j;
  if (j == 0) return i;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i-1] == s2[j-1]) return dp[i][j] = helper2(i - 1, j - 1, s1, s2, dp);
  // 1 + min(insertion, min(deletion, replacement)
  else return dp[i][j] = 1 + min(helper2(i, j - 1, s1, s2, dp), min(helper2(i - 1, j, s1, s2, dp), helper2(i - 1, j - 1, s1, s2, dp)));
}

int editDistance2(string s1, string s2) {
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
  return helper2(s1.size(), s2.size(), s1, s2, dp);
}

int editDistance3(string s1, string s2) {
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
  for (int i = 0; i<= s2.size(); i++) dp[i][0] = i;
  for (int j = 0; j <= s2.size(); j++) dp[0][j] = j;

  for(int i=1; i<=s1.size(); i++){
    for(int j=1; j<=s2.size(); j++){
      if (s1[i-1] == s2[j-1]) dp[i][j] =  dp[i - 1][j - 1];
      // 1 + min(insertion, min(deletion, replacement)
      else dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
    }
  }
  return dp[s1.size()][s2.size()];
}

int editDistance4(string s1, string s2) {
  vector<int> prev (s2.size() + 1, 0), curr (s2.size() + 1, 0);
  for (int j = 0; j <= s2.size(); j++) prev[j] = curr[j] = j;

  for(int i=1; i<=s1.size(); i++){
    curr[0] = i;
    for(int j=1; j<=s2.size(); j++){
      if (s1[i-1] == s2[j-1]) curr[j] =  prev[j - 1];
      // 1 + min(insertion, min(deletion, replacement)
      else curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
    }
    prev = curr;
  }
  return prev[s2.size()];
}

int editDistance4(string s1, string s2) {
  vector<int> prev (s2.size() + 1, 0), curr (s2.size() + 1, 0);
  for (int j = 0; j <= s2.size(); j++) prev[j] = curr[j] = j;

  for(int i=1; i<=s1.size(); i++){
    curr[0] = i;
    for(int j=1; j<=s2.size(); j++){
      if (s1[i-1] == s2[j-1]) curr[j] =  prev[j - 1];
      // 1 + min(insertion, min(deletion, replacement)
      else curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
    }
    prev = curr;
  }
  return prev[s2.size()];
}



int main() {
  string s1 = "horse";
  string s2 = "ros";
  cout << editDistance(s1, s2) << "\n";
  cout << editDistance2(s1, s2) << "\n";
  cout << editDistance3(s1, s2) << "\n";
  cout << editDistance4(s1, s2) << "\n";

  return 0;
}