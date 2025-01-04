// 115. Distinct Subsequences
// compare to s2 with s1 and compare how many s2 occurances are availabel in s1
#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (j < 0) return 1;
  if (i < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i] == s2[j]) {
    return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp) + helper(i - 1, j, s1, s2, dp);
  } else
    return dp[i][j] = helper(i - 1, j, s1, s2, dp);
}

int distinctSubsequence(string s1, string s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  return helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
}

int helper2(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if (j < 0) return 1;
  if (i < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i-1] == s2[j-1]) {
    return dp[i][j] = helper2(i - 1, j - 1, s1, s2, dp) + helper2(i - 1, j, s1, s2, dp);
  } else
    return dp[i][j] = helper2(i - 1, j, s1, s2, dp);
}

int distinctSubsequence2(string s1, string s2) {
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
  return helper2(s1.size(), s2.size(), s1, s2, dp);
}

int distinctSubsequence3(string s1, string s2) {
  vector<vector<double>> dp(s1.size()+1, vector<double>(s2.size()+1, 0));
  // for(int j=1; j<=s2.size(); j++) dp[0][j] = 0;
  for(int i=0; i<=s1.size(); i++) dp[i][0] = 1;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return (int)dp[s1.size()][s2.size()];
}
int distinctSubsequence4(string s1, string s2) {
  vector<double>prev(s2.size()+1, 0), curr(s2.size()+1, 0);
  // for(int j=1; j<=s2.size(); j++) dp[0][j] = 0;
  // for(int i=0; i<=s1.size(); i++) dp[i][0] = 1;
  prev[0] = curr[0] = 1;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i-1] == s2[j-1]) {
        curr[j] = prev[j - 1] + prev[j];
      }else {
        curr[j] = prev[j];
      }
    }
    prev = curr;
  }
  return (int)prev[s2.size()];
}
int distinctSubsequence5(string s1, string s2) {
  vector<double>prev(s2.size()+1, 0), curr(s2.size()+1, 0);
  // for(int j=1; j<=s2.size(); j++) dp[0][j] = 0;
  // for(int i=0; i<=s1.size(); i++) dp[i][0] = 1;
  prev[0] = curr[0] = 1;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = s2.size(); j >= 1; j--) {
      if (s1[i-1] == s2[j-1]) {
        curr[j] = prev[j - 1] + prev[j];
      }
    }
    prev = curr;
  }
  return (int)prev[s2.size()];
}
int distinctSubsequence6(string s1, string s2) {
  vector<double>prev(s2.size()+1, 0);
  // for(int j=1; j<=s2.size(); j++) dp[0][j] = 0;
  // for(int i=0; i<=s1.size(); i++) dp[i][0] = 1;
  prev[0] = 1;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = s2.size(); j >= 1; j--) {
      if (s1[i-1] == s2[j-1]) {
        prev[j] = prev[j - 1] + prev[j];
      }
    }
  }
  return (int)prev[s2.size()];
}


int main() {
  string s1 = "baggbag";
  string s2 = "bag";

  cout << distinctSubsequence(s1, s2) << "\n";
  cout << distinctSubsequence2(s1, s2) << "\n";
  cout << distinctSubsequence3(s1, s2) << "\n";
  cout << distinctSubsequence4(s1, s2) << "\n";
  cout << distinctSubsequence5(s1, s2) << "\n";
  cout << distinctSubsequence6(s1, s2) << "\n";

  return 0;
}