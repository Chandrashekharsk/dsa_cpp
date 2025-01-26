#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int j, vector<int>& prices, int cap, vector<vector<int>>& dp, int fee){
  if(i>=prices.size()||j == cap*2) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  // even->buy  && odd->sell
  if(j%2==0) return dp[i][j]= max(-prices[i]+helper(i+1, j+1, prices, cap, dp, fee), helper(i+1, j, prices, cap, dp, fee));
  else return dp[i][j]= max(prices[i]-fee + helper(i+2, j+1, prices, cap, dp, fee), helper(i+1, j, prices, cap, dp, fee));
}

int maxProfit(vector<int>& prices){
  int cap = 12, fee = 2;
  vector<vector<int>> dp(prices.size(), vector<int>(cap*2, -1));
  return helper(0,0,prices, cap, dp, fee);
}

int maxProfit2(vector<int>& prices){
  int cap = 12, fee = 2;
  vector<vector<int>> dp(prices.size()+2, vector<int>((cap*2)+1, 0));

  for (int i=prices.size()-1; i>=0; --i){
    for(int j=(cap*2)-1; j>=0; --j){
      if(j%2==0) dp[i][j]= max(-prices[i]+dp[i+1][j+1], dp[i+1][j]);
      else dp[i][j]= max(prices[i]-fee +dp[i+2][j+1], dp[i+1][j]);
    }
  }
  return dp[0][0];
}

int main(){

  vector<int> prices = {3,3,5,0,0,3,1,4};
  cout<<maxProfit(prices)<<endl;
  cout<<maxProfit2(prices)<<endl;


  return 0;
}