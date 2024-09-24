#include<iostream>
#include<vector>
using namespace std;

int main(){

  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(5);
  cout<<"size: "<<vec.size()<<"\n";
  cout<<"capacity: "<<vec.capacity();

  return 0;
}