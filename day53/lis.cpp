#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
  if(i==nums.size()) return 0;
  if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx];

  int take = 0;
  if(prevIdx == -1 || nums[i]>nums[prevIdx]) take = 1 + helper(i+1, i, nums, dp);
  int notTake = helper(i+1, prevIdx, nums, dp);

  return dp[i][prevIdx+1] = max(take, notTake);
}

int lis(vector<int>& nums){
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
  return helper(0, -1, nums, dp);
}

int lis2(vector<int>& nums){
  vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

  for (int i=nums.size()-1; i>= 0; --i){
    for (int prevIdx=i-1; prevIdx>=-1; --prevIdx){
      int take = 0;
      if(prevIdx == -1 || nums[i]>nums[prevIdx]) take = 1 + dp[i+1][i+1];
      int notTake = dp[i+1][prevIdx+1];

      dp[i][prevIdx+1] = max(take, notTake);
    }
  }
  return dp[0][-1+1];
}

int lis3(vector<int>& nums){
  vector<int> prev(nums.size()+1, 0), curr(nums.size()+1, 0);

  for (int i=nums.size()-1; i>= 0; --i){
    for (int prevIdx=i-1; prevIdx>=-1; --prevIdx){
      int take = 0;
      if(prevIdx == -1 || nums[i]>nums[prevIdx]) take = 1 + prev[i+1];
      int notTake = prev[prevIdx+1];

      curr[prevIdx+1] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[-1+1];
}

int tabulationApproach(vector<int>& nums){
  vector<int> dp(nums.size(), 1), hash(nums.size(), 0);
  int maxi  = 0;
  int maxValIdx = 0;
  
  for(int i=0; i<nums.size(); ++i){
    hash[i] = i;
    for(int prev=0; prev<i; ++prev){
      if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }

    if(dp[i]>maxi){
      maxValIdx = i;
      maxi = dp[i];
    } 
  }
  
  vector<int> temp;
  cout<<"printing elements\n";
  while(nums[maxValIdx] != maxValIdx){
    temp.push_back(nums[maxValIdx]);
    maxValIdx = hash[maxValIdx];
  }
  reverse(temp.begin(), temp.end());
  for(auto it: temp) cout<<it<<" ";
  cout<<endl;

  return maxi;
}

int binarySearchApproach(vector<int>& nums){
  vector<int> temp;
  temp.push_back(nums[0]);

  for (int i=1; i<nums.size(); ++i){
    auto idx = lower_bound(temp.begin(), temp.end(), nums[i]);
    if(idx == temp.end()) temp.push_back(nums[i]);
    else *idx = nums[i];
  }
  for(auto& i: temp) cout<< i<<" ";
  cout<<endl;
  return temp.size();
}

int main(){
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout<< lis(nums)<<endl;
  cout<< lis2(nums)<<endl;
  cout<< lis3(nums)<<endl;
  cout<< tabulationApproach(nums)<<endl;
  cout<< binarySearchApproach(nums)<<endl;
  


  return 0;
}