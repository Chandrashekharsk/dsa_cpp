// Vector - when vector becomes full it update capacity by double size
// 1. capacity, size
// 2. push_back, pop_back
// 3. .at(), []
// 4. front, back
// 5. clear, empty, insert, erase

#include<iostream>
#include<vector>
using namespace std;

  

int main(){
  // vector<int> vec(3,10); // size, val
  // vector<int> vec2(vec);
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.emplace_back(4);
  cout<< vec.capacity()<<"\n";
  vec.pop_back();
  cout<< vec[1]<<" "<<vec.at(1)<<"\n";


  cout<<"\nfront"<<vec.front()<<" back"<<vec.back()<<"\n";
  // for(auto i: vec) cout<<i<<" ";
  // vec.erase(vec.begin()+1);
  // vec.erase(vec.begin(),vec.begin()+2); // last not included
  // vec.insert(vec.begin(),4);
  // vec.insert(vec.begin(),4,10);
  cout<<"\n";


  // for(auto i: vec) cout<<i<<" ";
  // for(vector<int> :: iterator it = vec.begin(); it != vec.end(); it++){
  //   cout<< *(it)<<" ";
  // }
  for(auto it = vec.begin(); it != vec.end(); it++){
    cout<< *(it)<<" ";
  }
  cout<<"\n";
  for(auto it = vec.rbegin(); it != vec.rend(); it++){
    cout<< *(it)<<" ";
  }


  return 0;
}