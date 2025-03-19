#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minMultiplications(vector<int>& arr, int start, int end){
  queue<pair<int,int>> q;
  q.push({start, 0});

  vector<int> dist(100000, 1e9);
  dist[start] = 0;
  int mod = 100000;

  while(!q.empty()){
    auto [node, steps] = q.front();
    q.pop();

    if(node == end) return steps;

    for(auto it : arr){
      int newNum = (node*it) % mod;
      if(steps+1 < dist[newNum]){
        dist[newNum] = steps+1;
        q.push({newNum, steps+1});
      }
    }
  }
  return -1;
};

int main(){
  vector<int> nums = {2, 3, 5};
  int start = 3, end = 30;
  cout << "Minimum multiplications: " << minMultiplications(nums, start, end) << endl;

  return 0;
}