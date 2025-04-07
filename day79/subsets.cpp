// 78. Subsets
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> ans;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> subset;
    for (int j = 0; j < n; ++j) {
      if (i & (1<<j)) {
        subset.push_back(nums[n-1-j]);
      }
    }
    ans.push_back(subset);
  }
  return ans;
}

void dfs(int i, vector<int>& subset, vector<int>& nums, vector<vector<int>>& ans){
  if(i == nums.size()){
    ans.push_back(subset);
    return;
  };

  //take
  subset.push_back(nums[i]);
  dfs(i+1, subset, nums, ans);
  subset.pop_back();
  //not take
  dfs(i+1, subset, nums, ans);
}

vector<vector<int>> recursiveSubsets(vector<int>& nums){
  int n = nums.size();
  vector<vector<int>> ans;
  vector<int> subset;
  dfs(0, subset, nums, ans);
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = subsets(nums);

  for (const auto& subset : result) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
  }
  cout<<"------------------"<<endl;

  vector<vector<int>> result2 = recursiveSubsets(nums);

  for (const auto& subset : result2) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}