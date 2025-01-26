#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
  if (i == prices.size() || cap == 0) return 0;
  if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

  if (buy == 1) {
    return dp[i][buy][cap] = max(-prices[i] + helper(i + 1, 0, cap, prices, dp), helper(i + 1, 1, cap, prices, dp));
  } else {
    return dp[i][buy][cap] = max(prices[i] + helper(i + 1, 1, cap - 1, prices, dp), helper(i + 1, 0, cap, prices, dp));
  }
}

int maxProfit(vector<int>& prices, int cap) {
  // here cap vec is size 3 because it can be 0|1|2
  vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
  return helper(0, 1, cap, prices, dp);
}


int maxProfit2(vector<int>& prices, int cap) {
  // here cap vec is size 3 because it can be 0|1|2
  vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
  for (int buy = 0; buy <= 1; ++buy) {
    for (cap = 0; cap <= 2; ++cap) {
      dp[prices.size()][buy][cap] = 0;
    }
  }
  for(int i=0; i<=prices.size(); ++i){
    for (int buy = 0; buy <= 1; ++buy) {
      dp[i][buy][0] = 0;
    }
  }

  for (int i=prices.size()-1; i>=0; --i){
    for(int buy=0; buy<=1; ++buy){
      for (int c=1; c<=cap; ++c){
        if (buy == 1) {
          dp[i][buy][c] = max(-prices[i] + dp[i + 1][0][c], dp[i+1][1][c]);
        } else {
          dp[i][buy][c] = max(prices[i] +dp[i + 1][1][c - 1], dp[i + 1][0][c]);
        }
      }
    }
  }
  return dp[0][1][2];
}

int maxProfit3(vector<int>& prices, int cap) {
  // here cap vec is size 3 because it can be 0|1|2
  vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
  for (int buy = 0; buy <= 1; ++buy) {
    for (cap = 0; cap <= 2; ++cap) {
      next[buy][cap] = curr[buy][cap] = 0;
    }
  }
  for (int buy = 0; buy <= 1; ++buy) {
    next[buy][0] = curr[buy][0] = 0;
  }

  for (int i=prices.size()-1; i>=0; --i){
    for(int buy=0; buy<=1; ++buy){
      for (int c=1; c<=cap; ++c){
        if (buy == 1) {
          curr[buy][c] = max(-prices[i] + next[0][c], next[1][c]);
        } else {
          curr[buy][c] = max(prices[i] +next[1][c - 1], next[0][c]);
        }
      }
    }
    next = curr;
  }
  return next[1][2];
}

int helper(int i,int j, vector<int>& prices, int cap, vector<vector<int>>& dp){
  if(i==prices.size()|| j == cap*2) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  // here 0, 1 are buy(because first should buy then sell) and 2, 3 are sell
  if(j%2 == 0){
    return dp[i][j]= max(-prices[i]+ helper(i+1, j+1, prices, cap, dp), helper(i+1, j, prices, cap, dp));
  }else{
    return dp[i][j]= max(prices[i]+ helper(i+1, j+1, prices, cap, dp), helper(i+1, j, prices, cap, dp));
  }
}
int maxProfit4(vector<int>& prices, int cap) {
  vector<vector<int>> dp(prices.size(), vector<int>(cap*2, -1));
  return helper(0, 0, prices, cap, dp);
}

int main() {
  vector<int> prices = {9, 12, 8, 5, 6, 1, 3, 1, 3};
  cout << maxProfit(prices, 2)<<endl;
  cout << maxProfit2(prices, 2)<<endl;
  cout << maxProfit3(prices, 2)<<endl;
  cout << maxProfit4(prices, 4)<<endl;

  return 0;
}