#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
  if (i < 0) {
    if (j < 0) return true;
    return false;
  }
  if (j < 0) {
    for (int x = i; x >= 0; --x) {
      if (s1[x] != '*') return false;
    }
    return true;
  }
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i] == s2[j] || s1[i] == '?')
    return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
  if (s1[i] == '*') {
    // match 0 string with * || match 1 string and still open for match more
    return dp[i][j] = helper(i - 1, j, s1, s2, dp) || helper(i, j - 1, s1, s2, dp);
  }
  return dp[i][j] = false;
}

bool wildcard(string& s1, string& s2) {
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  return helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
}

bool helper2(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
  if (i == 0) {
    if (j == 0) return true;
    return false;
  }
  if (j == 0) {
    for (int x = 1; x <= i; ++x) {
      if (s1[x-1] != '*') return false;
    }
    return true;
  }
  if (dp[i][j] != -1) return dp[i][j];

  if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
    return dp[i][j] = helper2(i - 1, j - 1, s1, s2, dp);
  if (s1[i-1] == '*') {
    // match 0 string with * || match 1 string and still open for match more
    return dp[i][j] = helper2(i - 1, j, s1, s2, dp) || helper2(i, j - 1, s1, s2, dp);
  }
  return dp[i][j] = false;
}

bool wildcard2(string& s1, string& s2) {
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
  return helper2(s1.size(), s2.size(), s1, s2, dp);
}

bool wildcard3(string& s1, string& s2) {
  vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
  dp[0][0] = true;
  for(int i=1; i<=s1.size(); ++i){
    bool fl = true;
    for (int k=1; k<= i; ++k){
      if(s1[k-1] != '*'){
        fl = false;
        break;
      }
    }
    dp[i][0] = fl;
  }

  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (s1[i-1] == '*') {
        // match 0 string with * || match 1 string and still open for match more
        dp[i][j] = dp[i-1][j] || dp[i][j-1];
      }else{
        dp[i][j] = false;
      }
    }
  }
  return dp[s1.size()][s2.size()];
}
bool wildcard4(string& s1, string& s2) {
  vector<bool> prev (s2.size() + 1, false), curr (s2.size() + 1, false);

  prev[0] = curr[0] = true;
  

  for (int i = 1; i <= s1.size(); ++i) {
    bool fl = true;
    for (int k=1; k<= i; ++k){
      if(s1[k-1] == '*'){
        fl = true;
        break;
      }
    }
    curr[0] = fl;

    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
        curr[j] = prev[j - 1];
      else if (s1[i-1] == '*') {
        // match 0 string with * || match 1 string and still open for match more
        curr[j] = prev[j] || curr[j-1];
      }else{
        curr[j] = false;
      }
    }
    prev = curr;
  }
  return prev[s2.size()];
}

int main() {
  string s1 = "ab?cd";
  // string s1 = "ab*cd";
  string s2 = "abdefcd";
  cout << wildcard(s1, s2);
  cout << wildcard2(s1, s2);
  cout << wildcard3(s1, s2);
  cout << wildcard4(s1, s2);

  return 0;
}