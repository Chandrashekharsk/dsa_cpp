#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
  if (i == prices.size()) return 0;
  if (dp[i][buy] != -1) return dp[i][buy];

  if (buy == 1) {
    int buyAction = -prices[i] + helper(i + 1, 0, prices, dp);
    int notBuy = helper(i + 1, 1, prices, dp);
    return dp[i][buy] = max(buyAction, notBuy);
  } else {
    int sellAction = prices[i] + helper(i + 1, 1, prices, dp);
    int notSell = helper(i + 1, 0, prices, dp);
    return dp[i][buy] = max(sellAction, notSell);
  }
}

int buySell(vector<int>& prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
  return helper(0, 1, prices, dp);
}

int helper2(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
  if (i == prices.size() + 1) return 0;
  if (dp[i][buy] != -1) return dp[i][buy];

  if (buy == 1) {
    int buyAction = -prices[i - 1] + helper2(i + 1, 0, prices, dp);
    int notBuy = helper2(i + 1, 1, prices, dp);
    return dp[i][buy] = max(buyAction, notBuy);
  } else {
    int sellAction = prices[i - 1] + helper2(i + 1, 1, prices, dp);
    int notSell = helper2(i + 1, 0, prices, dp);
    return dp[i][buy] = max(sellAction, notSell);
  }
}

int buySell2(vector<int>& prices) {
  vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
  return helper2(1, 1, prices, dp);
}

int buySell3(vector<int>& prices) {
  vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
  // dp[prices.size()][0] = dp[prices.size()][1] = 0;

  for (int i = prices.size() - 1; i >= 0; --i) {
    for (int buy = 0; buy <= 1; ++buy) {
      if (buy == 1) {
        int buyAction = -prices[i] + dp[i + 1][0];
        int notBuy = dp[i + 1][1];
        dp[i][buy] = max(buyAction, notBuy);
      } else {
        int sellAction = prices[i] + dp[i + 1][1];
        int notSell = dp[i + 1][0];
        dp[i][buy] = max(sellAction, notSell);
      }
    }
  }
  return dp[0][1];
}

int buySell4(vector<int>& prices) {
  vector<int> next(2, 0), curr(2, 0);
  // dp[prices.size()][0] = dp[prices.size()][1] = 0;

  for (int i = prices.size() - 1; i >= 0; --i) {
    for (int buy = 0; buy <= 1; ++buy) {
      if (buy == 1) {
        int buyAction = -prices[i] + next[0];
        int notBuy = next[1];
        curr[buy] = max(buyAction, notBuy);
      } else {
        int sellAction = prices[i] + next[1];
        int notSell = next[0];
        curr[buy] = max(sellAction, notSell);
      }
      next = curr;
    }
  }
  return next[1];
}

int buySell5(vector<int>& prices) {
  int nextNotBuy = 0, nextBuy = 0;
  int currNotBuy = 0, currBuy = 0;

  for (int i = prices.size() - 1; i >= 0; --i) {
    currBuy = max(-prices[i] + nextNotBuy, nextBuy);
    currNotBuy = max(prices[i] + nextBuy, nextNotBuy);

    nextBuy = currBuy;
    nextNotBuy = currNotBuy;
  }

  return nextBuy;
}

int main() {
  vector<int> prices = {7, 2, 3, 5};
  cout << buySell(prices) << endl;
  cout << buySell2(prices) << endl;
  cout << buySell3(prices) << endl;
  cout << buySell4(prices) << endl;
  cout << buySell5(prices) << endl;
  return 0;
}
