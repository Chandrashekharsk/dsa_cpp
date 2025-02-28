#include <iostream>
#include <vector>
using namespace std;

int trappingRainwater(vector<int>& heights) {
  if (heights.empty()) return {};  // Handle empty input
  int n = heights.size();
  vector<int> lMax(n), rMax(n), water(n);

  // Compute left max array
  lMax[0] = heights[0];
  for (int i = 1; i < n; ++i) {
    lMax[i] = max(lMax[i - 1], heights[i]);
  }

  // Compute right max array
  rMax[n - 1] = heights[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    rMax[i] = max(rMax[i + 1], heights[i]);
  }

  // Calculate trapped water at each index
  for (int i = 0; i < n; ++i) {
    water[i] = max(0, min(lMax[i], rMax[i]) - heights[i]);
  }

  int ans = 0;
  for(auto val: water) ans+=val;

  return ans;
}

int trappingWater2(vector<int>& heights) {
  if(heights.empty()) return {};
  int n = heights.size();
  vector<int> lMax(n), rMax(n), water(n);

  lMax[0] = heights[0];
  rMax[n-1] = heights[n-1];
  int i=1, j = n-2;
  while(i<n && j>=0){
    lMax[i] = max(lMax[i-1], heights[i]);
    rMax[j] = max(rMax[j+1], heights[j]);
    ++i; --j;
  }

  for(int i=0; i<n; ++i){
    water[i] = max(0, min(rMax[i], lMax[i]) - heights[i]);
  }

  int ans = 0;
  for(auto val: water) ans+=val;
  return ans;
}

int trappingWater3(vector<int>& heights){
  int n = heights.size(), ans = 0;
  int start=0, end = n-1, lmax = 0, rmax = 0;

  while(start<end){ 
    lmax = max(lmax, heights[start]);
    rmax = max(rmax, heights[end]);
    if(lmax<=rmax){
      ans+= max(0, lmax - heights[start]);
      ++start;
    }else{
      ans+= max(0, rmax - heights[end]);
      --end;
    }
  }
  return ans;
};


int main() {
  vector<int> heights = {4, 2, 0, 3, 2, 5};
  // cout<<trappingRainwater(heights);
  // cout<<trappingWater2(heights);
  cout<<trappingWater3(heights);

}