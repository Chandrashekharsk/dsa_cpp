#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){

  vector<int> vec = {8,6,1,4,9,7,3,2};
  cout<< binary_search(vec.begin(), vec.end(),4)<<"\n";
  cout<< binary_search(vec.begin(), vec.end(),5)<<"\n";


  return 0;
}