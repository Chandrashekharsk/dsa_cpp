// 198. House Robber
#include<iostream>
#include<vector>
using namespace std;

int maxSumOfNonAdjancentSequence(int i, vector<int> nums){
  if(i==0) return nums[i];
  if(i<0) return 0;

  int pick = nums[i] + maxSumOfNonAdjancentSequence(i-2, nums);
  int notPick = maxSumOfNonAdjancentSequence(i-1, nums);
  return max(pick, notPick);
}

// memoization
int maxSumOfNonAdjancentSequence2(int i, vector<int> nums, vector<int> memo){
  if(i==0) return nums[i];
  if(i<0) return 0;
  if(memo[i] != -1) return memo[i];

  int pick = nums[i] + maxSumOfNonAdjancentSequence2(i-2, nums, memo);
  int notPick = maxSumOfNonAdjancentSequence2(i-1, nums, memo);
  return memo[i] = max(pick, notPick);
}

// tabulation
int maxSumOfNonAdjancentSequence3(vector<int> nums){
  vector<int> dp(nums.size()+1, -1);

  dp[0] = nums[0];
  for(int i=1; i<nums.size(); i++){

    int pick = nums[i] + (i>1? dp[i-2]: 0) ;
    int notPick = 0 + dp[i-1];
    dp[i] = max(pick, notPick);
  }
  return dp[nums.size()-1];
}

// optimized tabulation
int maxSumOfNonAdjancentSequence4(vector<int> nums){
  if(nums.size()== 0 ) return 0;
  if(nums.size()== 1 ) return nums[0]; // Handle single-element case

    int prev2 = 0;  // dp[i-2]
    int prev = nums[0];  // dp[i-1]

  for(int i=1; i<nums.size(); i++){

    int pick = nums[i] + (i>1? prev2: 0) ;
    int notPick = 0 + prev;
    int curr = max(pick, notPick);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int main(){
  vector<int> nums = { 2,1,4,9};

  cout<< maxSumOfNonAdjancentSequence(nums.size()-1, nums)<<"\n";

  vector<int> memo (nums.size()+1, -1);
  cout<< maxSumOfNonAdjancentSequence2(nums.size()-1, nums, memo)<<"\n";

  cout<< maxSumOfNonAdjancentSequence3(nums)<<"\n";
  cout<< maxSumOfNonAdjancentSequence4(nums)<<"\n";
  return 0;
}