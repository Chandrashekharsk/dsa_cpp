// 88.merge 2 sorted arrays
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
  int i = m-1, j = n-1, idx = m+n-1;

  while(i>=0 && j>=0){
    if(nums1[i]>nums2[j]){
      nums1[idx] = nums1[i];
      idx--; i--;
    }else{
      nums1[idx] = nums2[j];
      idx--; j--;
    }
  }
  while(j>=0){
    nums1[idx] = nums2[j];
    idx--; j--;
  }
}

int main(){

vector<int> vec1 = {1,3,4,0,0,0};
vector<int> vec2 = {2,5,6};
merge(vec1, 3, vec2, vec2.size());
for(auto i: vec1) cout<< i<<" ";
  return 0;
}