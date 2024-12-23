#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int N, vector<int>& prices, vector<vector<int>>& dp) {
  if (i == 0) return N * prices[i];
  if (dp[i][N] != -1) return dp[i][N];

  int rodLength = i + 1;
  int pick = -1e9;
  if (prices[i] <= N) pick = prices[i] + helper(i, N - (rodLength), prices, dp);
  int notPick = helper(i - 1, N, prices, dp);
  return dp[i][N] = max(pick, notPick);
}

int rodCutting(vector<int>& prices, int N) {
  vector<vector<int>> dp(prices.size(), vector<int>(N + 1, -1));
  return helper(prices.size() - 1, N, prices, dp);
}

int rodCutting2(vector<int>& prices, int N) {
  vector<vector<int>> dp(prices.size(), vector<int>(N + 1, 0));

  for (int j = 0; j <= N; j++) dp[0][j] = j * prices[0];

  for (int i = 1; i < prices.size(); i++) {
    for (int j = 0; j <= N; j++) {

      int rodLength = i + 1;
      int pick = -1e9;
      if (prices[i] <= j) pick = prices[i] + dp[i][j-(rodLength)];
      int notPick = dp[i - 1][j];
      dp[i][j] = max(pick, notPick);
    }
  }
  return dp[prices.size()-1][N];
}
int rodCutting3(vector<int>& prices, int N) {
  vector<int> prev(N + 1, 0), curr(N + 1, 0);

  for (int j = 0; j <= N; j++) prev[j] = curr[j] = j * prices[0];

  for (int i = 1; i < prices.size(); i++) {
    for (int j = 0; j <= N; j++) {

      int rodLength = i + 1;
      int pick = -1e9;
      if (prices[i] <= j) pick = prices[i] + curr[j-(rodLength)];
      int notPick = prev[j];
      curr[j] = max(pick, notPick);
    }
    prev = curr;
  }
  return prev[N];
}
int rodCutting4(vector<int>& prices, int N) {
  vector<int> prev(N + 1, 0), curr(N + 1, 0);

  for (int j = 0; j <= N; j++) prev[j] = j * prices[0];

  for (int i = 1; i < prices.size(); i++) {
    for (int j = 0; j <= N; j++) {

      int rodLength = i + 1;
      int pick = -1e9;
      if (prices[i] <= j) pick = prices[i] + prev[j-(rodLength)];
      int notPick = prev[j];
      prev[j] = max(pick, notPick);
    }
  }
  return prev[N];
}



int main() {
  vector<int> prices = {3, 5};
  int N = 12;

  cout << rodCutting(prices, N) << "\n";
  cout << rodCutting2(prices, N) << "\n";
  cout << rodCutting3(prices, N) << "\n";
  cout << rodCutting4(prices, N) << "\n";

  return 0;
}