// 78. Subsets 
#include <iostream>
#include <vector>
using namespace std;

void helper(int i, vector<int>& nums, vector<int>& subsets,
  vector<vector<int>>& ans) {
  if (i == nums.size()) {
    ans.push_back({subsets});
    return;
  };

  // include
  subsets.push_back(nums[i]);
  helper(i + 1, nums, subsets, ans);

  // exclude
  subsets.pop_back();  // backtrack
  helper(i + 1, nums, subsets, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<int> subsets;
  vector<vector<int>> ans;
  helper(0, nums, subsets, ans);
  return ans;
}

int main() {
  vector<int> nums{1, 2, 3};       // Input array
  for(auto i: subsets(nums)){
    for(auto j: i){
      cout<< j<<" ";
    }
    cout<<endl;
  };

  return 0;
}
