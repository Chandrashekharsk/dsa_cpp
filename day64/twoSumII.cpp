// 167. Two Sum II - Input Array Is Sorted
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum2(vector<int>& nums, int target) {
  vector<int> ans;
  int start = 0, end = nums.size()-1;

  while(end>start){
    int currSum =  nums[start]+nums[end];
    if(currSum==target){
      ans.push_back(start+1);
      ans.push_back(end+1);
      break;
    }else if(currSum<target){
      ++start;
    }else{
      --end;
    };
  }
  return ans;
}

int main(){

  vector<int> nums = {2,7,11,15};
  auto ans = twoSum2(nums, 9);
  for(int i=0; i<ans.size(); ++i){
    cout<<ans[i];
  }


  return 0;
}