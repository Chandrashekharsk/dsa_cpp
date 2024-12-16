// 90. Subsets II
// Subsets of n = pow(2,n);
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

void helper(int i, vector<int>& nums, vector<int>& subsets,
  vector<vector<int>>& ans, unordered_set<string>& s) {

  if (i == nums.size()) {
    string sub_str = "";

    for(int i=0; i<subsets.size(); i++){
      sub_str += to_string(subsets[i])+",";
    }

    if(s.find(sub_str) == s.end()){
      s.insert(sub_str);
      ans.push_back(subsets);
    }
    return;
  };

  // include
  subsets.push_back(nums[i]);
  helper(i + 1, nums, subsets, ans, s);

  // exclude
  subsets.pop_back();  // backtrack
  helper(i + 1, nums, subsets, ans, s);
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<int> subsets;
  vector<vector<int>> ans;
  unordered_set<string> s;
  helper(0, nums, subsets, ans, s);
  return ans;
}


void helper2(int i, vector<int>& nums, vector<int>& subSets, vector<vector<int>>& ans){

  if(i == nums.size()){
    ans.push_back(subSets);
    return;
  }
  
  // include
  subSets.push_back(nums[i]);
  helper2(i+1, nums, subSets, ans);

  // exclude
  subSets.pop_back();  // backtrack
  int next = i+1;
  while(next<nums.size() && nums[next] == nums[next-1]) next++;
  helper2(next, nums, subSets, ans);
};

vector<vector<int>> subsets2(vector<int>& nums){
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> subSets;
  helper2(0, nums, subSets, ans);
  return ans;
}

int main() {
  vector<int> nums{1, 2, 2};       // Input array

  // for(auto i: subsets(nums)){
  //   for(auto j: i){
  //     cout<< j<<" ";
  //   }
  //   cout<<endl;
  // };

  for(auto i: subsets2(nums)){
    for(auto j: i){
      cout<< j<<" ";
    }
    cout<<endl;
  };


  return 0;
}
