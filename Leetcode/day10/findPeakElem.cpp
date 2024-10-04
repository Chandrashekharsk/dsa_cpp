// 162: find any peak element
#include <iostream>
#include <vector>
using namespace std;


int findPeakIndex(vector<int> &nums){
  int st = 0, end = nums.size()-1;

  while(st<end){
    int mid = st + (end - st)/2;

    if(nums[mid]> nums[mid+1]){
      // search in left part 
      end = mid;
    }else{
      // search in right part 
      st = mid +1;
    }
  }
  return st;
}

int main()
{

  // vector<int> vec = {1, 2, 1, 3, 5, 6, 4};
  vector<int> vec = {1,2,1};
  // vector<int> vec = {1,2};
  cout << findPeakIndex(vec);

  return 0;
}