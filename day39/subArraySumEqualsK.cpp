// 560. Subarray Sum Equals K
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k){
  int count = 0;
  for(int i=0; i<nums.size(); i++){
    int sum = 0;
    for(int j=i; j<nums.size(); j++){
      sum += nums[j];
      if(sum == k) count++;
    }
  }
  return count;
}

int subarraySum2(vector<int>& nums, int k){
  int count = 0, prevSum = 0;
  unordered_map<int, int> mp;
  mp[0]=1; // store frequency

  for(int i=0; i<nums.size(); i++){
    prevSum += nums[i];
    int remove = prevSum - k;
    count += mp[remove];
    // cout<<"val: "<<remove<< " count: "<<count <<"\n"; 
    
    // update frequency
    mp[prevSum]++;
  }
  return count;
}

int main(){
  int k=3;
  // vector<int> nums  = {1,1,1};
  // vector<int> nums  = {1,2,3};
  vector<int> nums  = {3,-3, 3};
  cout<< subarraySum(nums,k)<<"\n";
  cout<< subarraySum2(nums,k)<<"\n";


  return 0;
}