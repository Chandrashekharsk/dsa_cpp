// 46. Permutations
// permutaions of n = n!
#include<iostream>
#include<vector> 
using namespace std;


void helper(int idx, vector<int>& nums,  vector<vector<int>>& ans){
  // idx => place value needs to pe filled
  if(idx==nums.size()){
    ans.push_back({nums});
    return;
  }

  for(int i = idx; i<nums.size(); i++){
    swap(nums[idx], nums[i]);
    helper(idx+1, nums, ans);
    swap(nums[idx], nums[i]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>>ans;
  helper(0, nums, ans);
  return ans;
}

int main(){
  vector<int> nums = {1,2,3};
  for(auto i: permute(nums)){
    for(auto j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  };


  return 0;
}