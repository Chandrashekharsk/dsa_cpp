#include<iostream>
#include<vector>
using namespace std;

int helper(int r, int c, vector<vector<int>>& nums, vector<vector<int>> dp){
  if(r == 0 && c == 0) return 1;
  if(r<0 || c<0) return 0;
  if(dp[r][c] != -1) return dp[r][c];

  int up = helper(r-1, c, nums, dp);
  int left = helper(r, c-1, nums, dp);
  return dp[r][c] = up+left;
}

int sumOfUniquePath(vector<vector<int>> nums){
  vector<vector<int>> dp(nums.size()+1, vector<int> (nums[0].size(), -1));
  return helper(nums.size()-1, nums[0].size()-1, nums, dp);
}

int sumOfUniquePath2(vector<vector<int>>& nums){
  vector<vector<int>> dp(nums.size(), vector<int> (nums[0].size(), 0));
  dp[0][0] = 1;
  for(int i=0; i<nums.size(); i++){
    for(int j=0; j<nums[0].size(); j++){

      if(i==0 && j== 0) continue;
      else{
        int up = (i > 0) ? dp[i - 1][j] : 0;    // Check boundary for up
        int left = (j > 0) ? dp[i][j - 1] : 0;  // Check boundary for left
        dp[i][j] = up+left;
      }
    }
  }
  return dp[nums.size()-1][nums[0].size()-1];
}

int sumOfUniquePath3(vector<vector<int>>& nums){
  vector<int> prev (nums[0].size(), 0);
  prev[0] = 1;
  for(int i=0; i<nums.size(); i++){
    vector<int> curr (nums[i].size(), 0);
    for(int j=0; j<nums[0].size(); j++){

      if(i==0 && j== 0) curr[j] = 1;
      else{
        int up = (i > 0) ? prev[j] : 0;    // Check boundary for up
        int left = (j > 0) ? curr[j - 1] : 0;  // Check boundary for left
        curr[j] = up+left;
      }
    }
    prev = curr;
  }
  return prev[nums[0].size()-1];
}


int main(){
  vector<vector<int>> nums = {{1,2},{3,4},{5,6}};
  cout<< sumOfUniquePath(nums)<<"\n";
  cout<< sumOfUniquePath2(nums)<<"\n";
  cout<< sumOfUniquePath3(nums)<<"\n";
  return 0;
}