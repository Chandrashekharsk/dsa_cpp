// 15. 3Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size();
  // vector<vector<int>> nv(1,vector<int>(3,0)); // size, value
  vector<vector<int>> nv;
  sort(nums.begin(), nums.end());

  for(int i=0; i<n-2; i++){
    // avoid duplicates
    if(i !=0 && nums[i] == nums[i-1]) continue;
    int st = i+1, end = n-1;

    while(st<end){
      int sum = nums[i] + nums[st] + nums[end];
      if(sum == 0){
        nv.push_back({nums[i], nums[st], nums[end]});
        while(st<end && nums[st] == nums[st+1]) st++;
        while(st<end && nums[end] == nums[end-1]) end--;
        st++;
        end--;

      }else if (sum<0){
        st++;
      }else{
        end--;
      }
    }
  }
  return nv;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // vector<int> nums = {-1, 0, -4};
  for(const auto& triplets: threeSum(nums)){
    for(int i: triplets){
      cout<< i<<" ";
    }
    cout<< "\n";
  }
}
