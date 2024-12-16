// 238. Product of Array Except Self
#include<iostream>
#include<vector>
using namespace std;

// brute force approach  -  O(n^2), O(n)
// vector<int> productExceptSelf(vector<int>& nums) {
//   int n = nums.size();
//   vector<int> ans(n,1);
//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//       if(i!=j){
//       ans[i] *= nums[j];
//       }
//     }
//   }
//   return ans;
// }

// optimal approach  -  O(n), O(n)(acc. to Ques here n is output array and it will not include in extra space)
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(n,1);
  
  // priffix
  for(int i=1; i<n; i++){
    // current value preffix
    ans[i] = ans[i-1] * nums[i-1];
  }

  // suffix
  int suffix = 1;
  for(int j=n-2; j>=0; j--){
    suffix = suffix * nums[j+1];
    // ans[preffix] * suffix
    ans[j] *= suffix;
  }
  return ans;
}

int main(){
  vector<int> vec = {1,2,3,4};
  for(int i: productExceptSelf(vec)){
    cout<<i<<" ";
  }

  return 0;
}