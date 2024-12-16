// agressive cows : variation of book allowcation
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int> nums, int N, int maxAllowedDist, int C){
  int cows = 1, lastStallPos = nums[0];
  for(int i=0; i<N; i++){
    if(nums[i]-lastStallPos>=maxAllowedDist){
      cows++;  
      lastStallPos = nums[i];
    }
    if(cows == C) return true;
  }
  return false;
}

int getDistance(vector<int>& nums, int N, int C){
  sort(nums.begin(), nums.end());
  int st= 1, end= nums[0] - nums[N-1], ans= -1;

  while(st<=end){
    int mid = st + (end-st)/2;
    if(isPossible(nums, N, mid, C)){
      ans = mid;
      st = mid+1;
    }else{
      end = mid-1;
    }
  }
  return ans; 
}


int main(){



  return 0;
}