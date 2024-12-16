#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
  // cout<< min(4,5)<<"\n";
  // cout<< max(4,5)<<"\n";

  // int a = 5, b=10;
  // cout<<"intially: "<<a<<" "<<b<<"\n";
  // swap(a, b);
  // cout<<"after swap: "<<a<<" "<<b<<"\n";

  vector<int> vec = {5,3,2,6};
  cout<<"maxElem: "<< *max_element(vec.begin(), vec.end())<<"\n";
  cout<<"minElem: "<< *min_element(vec.begin(), vec.end())<<"\n";


  return 0;
}