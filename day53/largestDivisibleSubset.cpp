#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lds(vector<int>& nums){
  vector<int> dp(nums.size(), 1), hash(nums.size());

  sort(nums.begin(), nums.end());
  int maxi = 1;
  int lastMaxIdx = 0;

  for (int i=0; i<nums.size(); ++i){
    hash[i] = i;
    for (int j=0; j<i; ++j){
      if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
        dp[i] = 1+dp[j];
        hash[i] = j;
      }
    }

    if(dp[i]>maxi){
      maxi = dp[i];
      lastMaxIdx = i;
    }
  };

  vector<int> temp;
  while(hash[lastMaxIdx] != lastMaxIdx){
    temp.push_back(nums[lastMaxIdx]);
    lastMaxIdx = hash[lastMaxIdx];
  }
  temp.push_back(nums[lastMaxIdx]);
  reverse(temp.begin(), temp.end());

  for (auto& it : temp) cout<<it<<" ";
  cout<<endl;
  return maxi;
}

int main(){
  vector<int> nums = {1, 4, 7, 8, 16, 19};
  cout<<lds(nums);


  return 0;
}