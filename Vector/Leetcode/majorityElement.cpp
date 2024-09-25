// Majority Element
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Brute force approach
// int majorityElement(vector<int>& nums){
//   int n = nums.size();
//   for(int i=0; i<n;i++){
//     int freq = 0;
//     for(int j=0; j<n; j++ ){
//       if(nums[i] == nums[j]){
//         freq++;
//       }
//     }
//     if(freq> n/2){
//       return nums[i];
//     } 
//   }
// }


// Little optimize approach  -  O(nlogn)
// int majorityElement(vector<int>& nums){
//   sort(nums.begin(), nums.end());
//   int n = nums.size();
//   int freq = 1, ans = nums[0];
//   for(int i=1; i<n; i++){
//     if(nums[i] == nums[i-1]){
//       freq++;
//     }else{
//       freq = 1; ans = nums[i];
//     }
//     if(freq> n/2) return nums[i];
//   }
// }


// Moore's algorithm
int majorityElement(vector<int>& nums){
  int n = nums.size();
  int freq = 0, ans = 0;
  for(int i=0; i<n; i++){
    if(freq == 0){
      freq= 1; ans= nums[i];
    }
    if(ans = nums[i]){
      freq++;
    } 
    else{
      freq--;
    }
  }
  return ans;
}

int main(){
  vector<int> nums = {2,2,1,1,1,2,2};
  cout<< majorityElement(nums);

  return 0;
}