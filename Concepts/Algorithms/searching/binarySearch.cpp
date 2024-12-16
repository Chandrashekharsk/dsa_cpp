// Binary Search  -  O(logn)
// To perform binary search array must be sorted
#include<iostream>
#include<vector>
using namespace std;

// simple binary search, it is optimize compare to recursive approach  -  O(logn) && O(l)
// int binarySearch(vector<int>& nums, int key){
//   int st = 0;
//   int ed = nums.size()-1;
//   while(ed>st){
//     // int mid = (st+ed)/2;
//     int mid = st + (ed-st)/2;
//     if(nums[mid] == key){
//       return mid;
//     }
//     // left-half
//     if(nums[mid]<key){
//       st = mid+1;
//     }
//     // second-half 
//     if(nums[mid]>key){
//       ed = mid-1;
//     }
//   }
//   return -1;
// }


// binary search using recursion  -  O(logn) && O(logn)
int RBS(vector<int> &nums,int key, int st, int ed){
  if(st>ed) return -1;

  int mid = st+ (ed-st)/2;
  if(nums[mid] ==  key) return mid;
  if(nums[mid]<key) return RBS(nums, key,mid+1, ed);
  if(nums[mid]>key) return RBS(nums,key,st, mid-1);
}
int binarySearch(vector<int>& nums, int key){
  int st= 0, ed= nums.size()-1;
  return RBS(nums, key, st, ed);
}

int main(){
vector<int> nums = {-2,0,3,4,5,9,12};
cout<< binarySearch(nums, 2)<<"\n";
cout<< binarySearch(nums, 9);

  return 0;
}