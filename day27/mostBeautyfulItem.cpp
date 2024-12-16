// 2070.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int binary_search(vector<vector<int>> items, int price){
  int st = 0, end = items.size()-1;
  int max_beauty = 0;

  while(st<=end){
    int mid = st + (end-st)/2;
    if(items[mid][0]<=price){
      max_beauty = max(max_beauty, items[mid][1]);
      st = mid+1;
    }else{
      end = mid-1;
    }
  }
  return max_beauty;
}

vector<int> maximumBeaty(vector<vector<int>> items, vector<int> queries){
  sort(items.begin(), items.end()); // sort price 

  for(int i=1; i<items.size(); ++i){ // sort beauties
    items[i][1] = max(items[i][1], items[i-1][1]);
  }

  vector<int> ans;
  for(int i=0; i<queries.size(); ++i){
    int max_beauty = binary_search(items, queries[i]);
    ans.push_back(max_beauty);
  }
  return ans;
}


int main(){

  vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
  vector<int> queries = {1,2,3,4,5,6};

  for(auto i: maximumBeaty(items, queries)){
    cout<<i<<" ";
  }

  return 0;
}