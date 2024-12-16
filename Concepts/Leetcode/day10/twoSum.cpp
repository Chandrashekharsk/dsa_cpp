// 1: two sum
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force approach  -  O(n^2)
// vector<int> findNums(vector<int>& nums, int tar){
//   vector<int> newVec;
//   for(int i=0; i<nums.size()-2; i++){
//     for(int j=1; j<nums.size()-1; j++){
//       if(nums[i]+nums[j] == tar){
//         newVec.push_back(i);
//         newVec.push_back(j);
//         return;
//       }
//     }
//   }
//   return newVec;
// }


// Optimize approach  -  O(n log n);
vector<int> findNums(vector<int>& nums, int tar){
  vector<pair<int, int>> newVec; // key-value pair  or  Object

  for(int i=0; i<nums.size(); i++){
    newVec.push_back({nums[i], i}); // value, index
  }
  sort(newVec.begin(), newVec.end());

  int st = 0; 
  int end = newVec.size()-1;
  while(st<end){
    int sum = newVec[st].first + newVec[end].first;
    if(sum == tar){
      return {newVec[st].second, newVec[end].second};
    }
    if(sum>tar){
      end--;
    }else{
      st++;
    }
  }
  return {};  // Return empty vector if no solution is found
}

int main(){

  vector<int> nums = {2,11,7,15};
  int target = 9;
  for(int i : findNums(nums, target)){
    cout<<i <<" ";
  }

  return 0;
}