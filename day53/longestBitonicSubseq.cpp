// Bitonic == totalIncresing | totalDecreasing | Both
#include<iostream>
#include<vector>
using namespace std;

int lbs(vector<int>& nums){
  vector<int> dp1(nums.size(), 1), dp2(nums.size(), 1);

  // fill dp1
  for(int i = 0; i<nums.size(); ++i){
    for (int prev = 0; prev<i; ++prev){
      if(nums[i]> nums[prev] && 1+dp1[prev]> dp1[i]){
        dp1[i] = 1+dp1[prev];
      }
    }
  }

  // fill dp2 and together compute max
  int maxi=1;
  for(int i = nums.size()-1; i>=0; --i){
    for (int prev = nums.size()-1; prev>i; --prev){
      if(nums[i]>nums[prev] && 1+dp2[prev]>dp2[i]){
        dp2[i] = 1+dp2[prev];
      }
    }
    maxi = max(dp1[i]+dp2[i]-1, maxi);
  }

  // PRINT DP1 && DP2
  for(int k =0; k<nums.size(); ++k) cout<< dp1[k]<<"-"<<dp2[k]<<" ";
  cout<<endl;

  return maxi;
}

int main(){

  vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
  cout<<lbs(nums);


  return 0;
}