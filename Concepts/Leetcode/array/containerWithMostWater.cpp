// 11. Container With Most Water
#include<iostream>
#include<vector>
using namespace std;

// brute force approach  - O(n^2)
// int maxArea(vector<int>& height) {
//   int n = height.size();
//   int ans = 0;
//   for(int i=0; i<n; i++){
//     for(int j=i+1; j<n; j++){
//       int wt = j-i;
//       int ht = min(height[i], height[j]);
//       ans = max(ans,ht*wt);
//     }
//   }
//   return ans;
// }

// optimal approach (2 pointer approach)  -  O(n)
int maxArea(vector<int>& height) {
  int mxWaterCont = 0;
  int i = 0;
  int j = height.size() - 1;
  while(j>i){
    int ht = j-i;
    int wt = min(height[j],height[i]);
    mxWaterCont = max(mxWaterCont,ht*wt);

    height[i]<height[j] ? i++: j--;
  }
  return mxWaterCont;
}


int main(){

  vector<int> vec = {1,8,6,2,5,4,8,3,7};
  cout<<maxArea(vec);

  return 0;
}