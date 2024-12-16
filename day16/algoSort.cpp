#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int> p1, pair<int,int>p2){
  if(p1.second<p2.second) return true;
  if(p1.second>p2.second) return false;

  if(p1.first<p2.first) return true;
  else return false;
}


int main(){
  // int arr[] = {1, 8, 9, 4}; 
  // int size = 4;
  // sort(arr, arr + size);
  // for (int i = 0; i < size; i++) {
  //   cout << arr[i] << " ";
  // }

  // vector<int> vec = {1, 8, 9, 4};
  // sort(vec.begin(), vec.end());
  // for decreasing fashion
  // sort(vec.begin(), vec.end(), greater<int>());
  // for(int i: vec) cout<< i<<" ";

  vector<pair<int,int>> p = {{5,2},{3,2},{5,8},{7,8}};
  sort(p.begin(), p.end(), comparator);
  for(auto val: p) cout<< val.first<<" "<<val.second<<"\n";

  return 0;
}