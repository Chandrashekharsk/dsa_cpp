#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (i < 0 || j < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i] == s2[j]) return 1 + helper(i - 1, j - 1, s1, s2, dp);
  return dp[i][j] =
             max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));
}

int lcs(string s1, string s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  return helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
}

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
  return dp[s1.size()][s2.size()];
}

int lcs4(string s1, string s2) {
  vector<int>prev (s2.size() + 1, 0), curr (s2.size() + 1, 0);

  for (int j = 0; j <= s2.size(); j++) prev[j]= curr[j] = 0;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) curr[j] = 1 + prev[j - 1];
      else curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
  }
  return prev[s2.size()];
}

int main() {
  string s1 = "abcd";
  string s2 = "cddf";

  cout << lcs(s1, s2) << "\n";
  cout << lcs2(s1, s2) << "\n";
  cout << lcs3(s1, s2) << "\n";
  cout << lcs4(s1, s2) << "\n";

  return 0;
}