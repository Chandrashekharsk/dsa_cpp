#include<iostream>
#include<vector>
using namespace std;

// using memoization
int frogJump(int i, vector<int> nums, vector<int> dp){
  if(i == 0) return 0;
  if(dp[i] != -1) return dp[i];


  int minOfAllPrevJumps = INT_MAX; 
  // exceed the valid range for i - j
  for(int j=1; j<=i; j++){
    int currJump = abs(nums[i] - nums[i-j]) + frogJump(i-j, nums,dp);
    minOfAllPrevJumps = min(minOfAllPrevJumps, currJump);
  }
  return dp[i] = minOfAllPrevJumps;
}

// using tabulation
int frogJump2( vector<int> nums){
  vector<int> dp(nums.size()+1, -1);
  dp[0] = 0;

  for(int i=1; i<nums.size(); i++){
    int minOfAllPrevJumps = INT_MAX;

    for(int j = 1; j<=i; j++){
      int currJump = abs(nums[j]-nums[i-j]) + dp[i-j];
      minOfAllPrevJumps = min(minOfAllPrevJumps, currJump);
    }
    dp[i] = minOfAllPrevJumps;
  }
  return dp[nums.size()-1];
}

int main(){

  vector<int> nums = {10, 30, 40, 50, 20}; // Heights of stones.
  int n = nums.size();
  vector<int> dp(n+1, -1); // Initialize dp array for memoization.
  
  cout << "Minimum cost to reach the last stone: "<< frogJump(n - 1, nums, dp) << endl;

  cout << "Minimum cost to reach the last stone: "<< frogJump2(nums) << endl;

  return 0;
}