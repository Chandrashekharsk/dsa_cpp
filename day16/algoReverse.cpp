#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){

  vector<int> vec = {1,2,4,6};
  reverse(vec.begin(), vec.end());
  for(auto i: vec) cout<<i<<" ";


  return 0;
}