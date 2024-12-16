// 410. Split Array Largest Sum

// Approach: Binary Search + Greedy Allocation   -  O(n log(Sum of pages))
#include <iostream>
#include <vector>
#include <algorithm>  // Include for using max_element
using namespace std;

bool isValid(vector<int>& nums, int size, int totalStudents, int maxAllowedPages) {
  int student = 1, pages = 0;
  for(int val: nums){
    if(val>maxAllowedPages) return false;

    if(pages+val <= maxAllowedPages){
      pages += val;
    }else{
      student++; 
      pages = val;
      if(student > totalStudents) return false;
    }
  }
  return student <= totalStudents;
}

int bookAllocationProblem(vector<int>& nums, int size, int totalStudents) {
  if(totalStudents > size) return -1;

    int st = *max_element(nums.begin(), nums.end()), ans = -1;
    int long long end = 0;
    for(int val : nums) end += val;

    while(st<=end){
      int mid = st + (end-st)/2;
      if(isValid(nums, size, totalStudents, mid)){
        ans = mid;
        end = mid-1;
      }else{
        st = mid+1;
      }
    }
    return ans;
}

int main() {
    vector<int> vec = {2, 1, 3, 4};
    cout << bookAllocationProblem(vec, vec.size(), 2);
    return 0;
}
