#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
  if(i==prices.size()) return 0;
  if(dp[i][buy]!= -1) return dp[i][buy];

  if(buy == 1){
    return dp[i][buy] = max(-prices[i]+helper(i+1, 0, prices, dp), helper(i+1, 1, prices, dp));
  }else{
    return dp[i][buy] = max(prices[i]+helper(i+1, 1, prices, dp), helper(i+1, 0, prices, dp));
  }
}

int maxProfit(vector<int>& prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
  return helper(0,1,prices, dp);
}

int maxProfit2(vector<int>& prices) {
  vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
  for(int j=0; j<=1; ++j) dp[prices.size()][j] = 0;

  for (int i=prices.size()-1; i>=0; --i){
    for (int buy=0; buy<=1; ++buy){
      if(buy == 1){
        dp[i][buy] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
      }else{
        dp[i][buy] = max(prices[i]+ dp[i+1][1], dp[i+1][0]);
      }
    }
  }
  return dp[0][1];
}

int maxProfit3(vector<int>& prices) {
  vector<int> next(2, 0), curr(2, 0);
  for(int j=0; j<=1; ++j) next[j] = curr[j] = 0;

  for (int i=prices.size()-1; i>=0; --i){
    for (int buy=0; buy<=1; ++buy){
      if(buy == 1) curr[buy] = max(-prices[i]+next[0], next[1]);
      else curr[buy] = max(prices[i]+ next[1], next[0]);
    }
    next = curr;
  }
  return next[1];
}


int main(){

  vector<int> prices = {1,2,3,4,5};
  cout<<maxProfit(prices)<<endl;
  cout<<maxProfit2(prices)<<endl;
  cout<<maxProfit3(prices)<<endl;


  return 0;
}