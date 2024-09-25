// majority element variation - when not given sure majority elem will definetly exists
#include<iostream>
#include<vector>
using namespace std;

// O(n)
int majorityElement(vector<int>& nums){
  int freq =0, ans= 0;

  for(int i=0; i<nums.size(); i++){
    if(freq == 0){
      freq = 1; ans = nums[i];
    }
    if(ans == nums[i]){
      freq++;
    }else{
      freq--;
    }
  }
  // return ans;

  // if not sure majority elem will exists
  int count = 0;
  for(int val: nums){
    if (ans == val){
      count++;
    }
  }
  if(count> nums.size()/2) return ans;
  else return -1;
}

int main(){
  vector<int> nums = {3,2,1,1,1,2,2};
  cout<< majorityElement(nums);

  return 0;
}