#include<iostream>
#include<vector>
using namespace std;

void helper(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr){
  if(i==nums.size()){
    ans.push_back(curr);
    return;
  }

  curr.push_back(nums[i]);
  helper(i+1, nums, ans, curr);
  curr.pop_back();
  helper(i+1, nums, ans, curr);
}

vector<vector<int>> subSeq(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> curr;
  helper(0, nums, ans,curr);
  return ans;
}

void helper2(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr){
  if(i<0){
    ans.push_back(curr); 
    return;
  }

  curr.push_back(nums[i]);
  helper2(i-1, nums, ans, curr);
  curr.pop_back();
  helper2(i-1, nums, ans, curr);
}

vector<vector<int>> subSeq2(vector<int>& nums){
  vector<vector<int>> ans;
  vector<int> curr;
  helper2(nums.size()-1, nums, ans,curr);
  return ans;
}

int main(){

  vector<int> nums = {3,1,2};
  // for(auto &it: subSeq(nums)){
  //   for (auto &it2: it) cout<<it2<<" ";
  //   cout<<"\n";
  // }
  // cout<<"\n";

  for(auto &it: subSeq2(nums)){
    for (auto &it2: it) cout<<it2<<" ";
    cout<<"\n";
  }


  return 0;
}