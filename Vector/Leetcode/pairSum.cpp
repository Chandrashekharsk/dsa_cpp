// return pair in sorted array with target sum.
#include<iostream>
#include<vector>
using namespace std;

// Brute force approach  -  O(n^2)
// vector<int> pairSum(vector<int> &vec, int targetSum){
//   vector<int> newvec;
//   int n = vec.size();
//   for(int i=0; i<n; i++){
//     for(int j=i; i<n; j++){
//       if(vec[i]+vec[j] == targetSum){
//         newvec.push_back(i);
//         newvec.push_back(j);
//         return newvec;
//       }
//     }
//   }
//   return newvec;
// }


// Because values are sorted order we can optimize it.
// optimize approach  -  O(n)
vector<int> pairSum(vector<int> &vec, int targetSum){
  vector<int> newvec;
  int n = vec.size();
  int st = 0;
  int end = vec.size()-1;

  while(end>st){
    if(vec[st] + vec[end] == targetSum){
      newvec.push_back(st);
      newvec.push_back(end);
      return newvec;
    }
    if(vec[st] + vec[end]> targetSum){
      end--;
    }
    if(vec[st] + vec[end] <targetSum){
      st++;
    }
  }
  return newvec;
}

int main(){

  vector<int> vec = {2,7,11,15};
  // int targetSum = 9;
  int targetSum = 13;
  for(int i: pairSum(vec, targetSum)){
    cout<<i<<" ";
  };


  return 0;
}