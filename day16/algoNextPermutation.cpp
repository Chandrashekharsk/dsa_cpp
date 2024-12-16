#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
  // vector<int> vec = {4,2,3};
  // next_permutation(vec.begin(), vec.end());
  // for(int i: vec) cout<<i<<" ";

  string str = "abc";
  cout<<str<<"\n";

  next_permutation(str.begin(), str.end());
  cout<<str<<"\n";
  prev_permutation(str.begin(), str.end());
  cout<<str<<"\n";

  return 0;
}