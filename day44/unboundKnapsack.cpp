#include <iostream>
#include <vector>
using namespace std;

int helper(int i, vector<int>& vals, vector<int>& weights, int cap,
           vector<vector<int>>& dp) {
  if (i == 0) return vals[i] * ((int)cap / weights[i]);
  if (dp[i][cap] != -1) return dp[i][cap];

  int pick = -1e9;
  if (weights[i] <= cap)
    pick = vals[i] + helper(i, vals, weights, cap - weights[i], dp);
  int notPick = helper(i - 1, vals, weights, cap, dp);
  return dp[i][cap] = max(pick, notPick);
}

int unboudKnapsack(vector<int>& vals, vector<int> weights, int cap) {
  vector<vector<int>> dp(vals.size(), vector<int>(cap + 1, -1));
  return helper(vals.size() - 1, vals, weights, cap, dp);
}

int unboudKnapsack2(vector<int>& vals, vector<int> weights, int cap) {
  vector<vector<int>> dp(vals.size(), vector<int>(cap + 1, 0));
  for (int j = 0; j <= cap; j++) {
    dp[0][j] = vals[0] * ((int)j / weights[0]);
  }

  for (int i = 1; i < vals.size(); i++) {
    for (int j = 0; j <= cap; j++) {
      int pick = -1e9;
      if (weights[i] <= cap)  pick = vals[i] + dp[i][cap - weights[i]];
      int notPick = dp[i - 1][cap];
      dp[i][cap] = max(pick, notPick);
    }
  }
  return dp[vals.size()-1][cap];
}

int unboudKnapsack3(vector<int>& vals, vector<int> weights, int cap) {
  vector<int> prev (cap + 1, 0), curr (cap + 1, 0);

  for (int j = 0; j <= cap; j++) {
    prev[j] = curr[j] = vals[0] * ((int)j / weights[0]);
  }

  for (int i = 1; i < vals.size(); i++) {
    for (int j = 0; j <= cap; j++) {
      int pick = -1e9;
      if (weights[i] <= cap)  pick = vals[i] + curr[cap - weights[i]];
      int notPick = prev[cap];
      curr[cap] = max(pick, notPick);
    }
    prev = curr;
  }
  return prev[cap];
}

int unboudKnapsack4(vector<int>& vals, vector<int> weights, int cap) {
  vector<int> curr (cap + 1, 0);

  for (int j = 0; j <= cap; j++) {
    curr[j] = vals[0] * ((int)j / weights[0]);
  }

  for (int i = 1; i < vals.size(); i++) {
    for (int j = 0; j <= cap; j++) {
      int pick = -1e9;
      if (weights[i] <= cap)  pick = vals[i] + curr[cap - weights[i]];
      int notPick = curr[cap];
      curr[cap] = max(pick, notPick);
    }
  }
  return curr[cap];
}

int main() {
  vector<int> vals = {14, 5, 8};
  vector<int> weights = {3, 2, 5};
  int cap = 7;

  cout << unboudKnapsack(vals, weights, cap)<<"\n";
  cout << unboudKnapsack2(vals, weights, cap)<<"\n";
  cout << unboudKnapsack3(vals, weights, cap)<<"\n";
  cout << unboudKnapsack4(vals, weights, cap)<<"\n";

  return 0;
}