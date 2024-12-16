#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumSubarrySum(vector<int> nums){
  int maxi = -1e9;
  for(int i=0; i<nums.size(); i++){
    int sum = 0;
    for(int j=i; j<nums.size(); j++){
      sum+= nums[j];
      maxi = max(sum, maxi);
    } 
  }
  return maxi;
}

// Kadane's algorithm
int maximumSubarrySum2(vector<int> nums){
  int maxi = -1e9;
  int sum = 0;
  for(int i=0; i<nums.size(); i++){
    sum += nums[i];
    maxi = max(maxi, sum);
    if(sum<0) sum = 0;
  }
  return maxi;
}


int main(){
  // vector<int> nums = {3, -4, 5, 4, -1, 7, -8};
  vector<int> nums = {3, -4, 5, 4, -1};
  cout<< maximumSubarrySum(nums)<<"\n";
  cout<< maximumSubarrySum2(nums)<<"\n";


  return 0;
}