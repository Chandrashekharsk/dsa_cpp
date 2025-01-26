#include<iostream>
#include<vector>
using namespace std;

int countOfLIs(vector<int>& nums){
  vector<int> dp(nums.size(),1), cnt(nums.size(),1);
  int maxi = 1;

  for (int i=0; i<nums.size(); ++i){
    for (int prev=0; prev<i; ++prev){
      if(nums[i]>nums[prev] && 1+dp[prev] > dp[i]){
        dp[i] = 1+dp[prev];
        // inherit the count
        cnt[i] = cnt[prev];
      }else if(nums[i]>nums[prev] && 1+dp[prev]==dp[i]){
        // increse the count 
        cnt[i] += cnt[prev];
      }
    }
    maxi = max(maxi, cnt[i]);
  }
  return maxi;
}

int main(){
  vector<int> nums = {1, 3, 5, 4, 7};
  cout<<countOfLIs(nums);

  return 0;
}