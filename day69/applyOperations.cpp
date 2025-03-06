// 2460. Apply Operations to an Array
#include<iostream>
#include<vector>
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
  vector<int>ans(nums.size(), 0);
  int idx = -1;

  for(int i=0; i<nums.size()-1; ++i){
    if( nums[i] == nums[i+1]){
      nums[i] = nums[i]*2;
      nums[i+1] = 0;
    }
    if(nums[i]!=0) ans[++idx] = nums[i];
  };
  ans[++idx] = nums[nums.size()-1];

  return ans;
}

int main(){
  // vector<int> nums = {1,2,2,1,1,0};
  vector<int> nums = {0,1};
  for(auto& i: applyOperations(nums)) cout<<i<<" ";
  cout<<endl;
  


  return 0;
}