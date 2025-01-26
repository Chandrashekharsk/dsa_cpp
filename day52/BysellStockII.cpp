#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int j, vector<int>& prices, int cap, vector<vector<int>>& dp){
  if(i==prices.size()||j == cap*2) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  // even->buy  && odd->sell
  if(j%2==0) return dp[i][j]= max(-prices[i]+helper(i+1, j+1, prices, cap, dp), helper(i+1, j, prices, cap, dp));
  else return dp[i][j]= max(prices[i]+helper(i+1, j+1, prices, cap, dp), helper(i+1, j, prices, cap, dp));
}

int maxProfit(vector<int>& prices){
  int cap = 2;
  vector<vector<int>> dp(prices.size(), vector<int>(cap*2, -1));
  return helper(0,0,prices, cap, dp);
}

int maxProfit2(vector<int>& prices){
  int cap = 2;
  vector<vector<int>> dp(prices.size()+1, vector<int>((cap*2)+1, 0));
  for(int i=0; i<=prices.size(); ++i) dp[i][cap*2] = 0;
  for(int j=0; j<=cap*2; ++j) dp[prices.size()][j] = 0;

  for (int i=prices.size()-1; i>=0; --i){
    for(int j=(cap*2)-1; j>=0; --j){
      if(j%2==0) dp[i][j]= max(-prices[i]+dp[i+1][j+1], dp[i+1][j]);
      else dp[i][j]= max(prices[i]+dp[i+1][j+1], dp[i+1][j]);
    }
  }
  return dp[0][0];
}

int maxProfit3(vector<int>& prices){
  int cap = 2;
  vector<int>next ((cap*2)+1, 0), curr ((cap*2)+1, 0);
  
  next[cap*2] = curr[cap*2] = 0;
  // for(int j=0; j<=cap*2; ++j) next[j] = curr[j] = 0;

  for (int i=prices.size()-1; i>=0; --i){
    for(int j=(cap*2)-1; j>=0; --j){
      if(j%2==0) curr[j]= max(-prices[i]+next[j+1], next[j]);
      else curr[j]= max(prices[i]+next[j+1], next[j]);
    }
    next = curr;
  }
  return next[0];
}

int main(){

  vector<int> prices = {3,3,5,0,0,3,1,4};
  cout<<maxProfit(prices)<<endl;
  cout<<maxProfit2(prices)<<endl;
  cout<<maxProfit3(prices)<<endl;


  return 0;
}