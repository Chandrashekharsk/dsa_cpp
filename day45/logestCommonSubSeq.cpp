#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (i < 0 || j < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  // Case match
  if (s1[i] == s2[j]) return dp[i][j] = 1 + helper(i - 1, j - 1, s1, s2, dp);
  // Case not match
  return dp[i][j] = max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));
}

int lcs(string s1, string s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  return helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
}


int lcs2(string s1, string s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));

  // Initialize first row and column
  for (int j = 0; j < s2.size(); j++) {
    if (s1[0] == s2[j]) dp[0][j] = 1;
    if (j > 0) dp[0][j] = max(dp[0][j], dp[0][j - 1]);
  }
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == s2[0]) dp[i][0] = 1;
    if (i > 0) dp[i][0] = max(dp[i][0], dp[i - 1][0]);
  }

  for (int i = 1; i < s1.size(); i++) {
    for (int j = 1; j < s2.size(); j++) {
      if (s1[i] == s2[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[s1.size() - 1][s2.size() - 1];
}

int lcs3(string s1, string s2) {
  vector<int> prev(s2.size(), 0), curr(s2.size(), 0);

  // Initialize first row
  for (int j = 0; j < s2.size(); j++) {
    if (s1[0] == s2[j]) prev[j] = 1;
    if (j > 0) prev[j] = max(prev[j], prev[j - 1]);
  }

  for (int i = 1; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) curr[j] = (j > 0 ? 1 + prev[j - 1] : 1);
      else curr[j] = max(prev[j], (j > 0 ? curr[j - 1] : 0));
    }
    prev = curr; // Move current row to previous row
  }

  return prev[s2.size() - 1];
}

int main() {
  string s1 = "abc";
  string s2 = "adc";

  cout << lcs(s1, s2) << "\n";
  cout << lcs2(s1, s2) << "\n";
  cout << lcs3(s1, s2) << "\n";

  return 0;
}
