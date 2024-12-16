#include<iostream>
#include<vector>
using namespace std;

int helper(int day, vector<vector<int>>& nums, int prevTask, vector<vector<int>>& dp){
  if(day==0){
    int maxi=INT_MIN;
    for(int task=0; task<3; task++){
      if( task != prevTask){
        maxi = max(maxi, nums[0][task]);
      }
    }
    return maxi;
  }
  if(dp[day][prevTask] != -1)  return dp[day][prevTask];

  int maxi = INT_MIN;
  for(int task=0; task<3; task++){
    if(task != prevTask){
      int currDayPoints = nums[day][task] + helper(day-1, nums, task, dp);
      maxi = max(maxi, currDayPoints);
    }
  }
  return dp[day][prevTask] = maxi;
}

int findMaxPoints(vector<vector<int>>& nums){
  vector<vector<int>> dp(nums.size()+1, vector<int>(4, -1));
  return helper(nums.size()-1, nums, 3, dp);
}

int findMaxPoints2( vector<vector<int>>& nums){
  vector<vector<int>> dp(nums.size()+1, vector<int>(4,0));

  dp[0][0] = max(nums[0][1], nums[0][2]);
  dp[0][1] = max(nums[0][0], nums[0][2]);
  dp[0][2] = max(nums[0][0], nums[0][1]);
  dp[0][3] = max(nums[0][0], max(nums[0][1], nums[0][2]));

  for(int i=1; i<nums.size(); i++){
    for(int prevTask=0; prevTask<4; prevTask++){
      
      dp[i][prevTask] = 0;
      for(int task=0; task<3; task++){
        if(task != prevTask){
          int currDayPoints = nums[i][task] + dp[i-1][task];
          dp[i][prevTask] = max(dp[i][prevTask], currDayPoints);
        }
      }
    }
  }

   // The answer is the maximum points achievable on the last day with no restrictions
  return dp[nums.size()-1][3];
}

int main(){

  vector<vector<int>> mat = {{1,3,5}, {8,5,3},{2,2,1}};
  // cout<<findMaxPoints(mat);

  cout<<findMaxPoints2(mat);


  return 0;
}