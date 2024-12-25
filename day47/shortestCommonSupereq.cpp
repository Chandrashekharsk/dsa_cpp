// Sortest common super sequence
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int MinInsertionToMakePal(string s1, string s2) {
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

  // fill 1st row and 1st col to for out of bounds base case
  // for(int j=0; j<=s2.size(); j++) dp[0][j] = 0;
  // for(int i=0; i<=s2.size(); i++) dp[i][0] = 0;

  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int i = s1.size() + 1, j = s2.size() + 1;
  string path = "";

  while (i>0 && j>0) {
    if (s1[i - 1] == s2[j - 1]) {
      path = s1[i - 1] + path;
      i--;
      j--;
    } else {
      if (dp[i - 1][j] > dp[j - 1][i]) {
        path = s1[i - 1] + path;
        i--;
      } else {
        path = s2[j - 1] + path;
        j--;
      }
    }
  }
  while(i>0) path = s1[i-1]+ path; i--;
  while(j>0) path = s1[j-1]+ path; j--;
  cout << path << "\n";

  int lcs = dp[s1.size()][s2.size()];
  int n = s1.size();
  int m = s2.size();
  return (n + m - lcs);
}

int main() {
  string s1 = "bleed";
  string s2 = "blue";
  cout << MinInsertionToMakePal(s1, s2);

  return 0;
}