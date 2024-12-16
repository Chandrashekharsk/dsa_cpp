// 2965. Find Missing and Repeated Values

#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
  vector<int> ans;
  unordered_set<int> s;
  int n = grid.size() * grid[0].size();
  int expectedSum = n* (n+1)/2, actualSum = 0, repeated = -1;
  

  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[i].size(); j++){

      if(s.find(grid[i][j]) != s.end()){
        repeated = grid[i][j];
      }
      actualSum+= grid[i][j];
      s.insert(grid[i][j]);
    }
  }
  int missingVal = expectedSum - (actualSum - repeated);
  ans.push_back(repeated);
  ans.push_back(missingVal);
  return ans;
}

int main(){
  // [[1,3],[2,2]]
  vector<vector<int>> grid = {{1,3},{2,2}};
  for(auto i : findMissingAndRepeatedValues(grid)){
    cout<<i<<" ";
  }


  return 0;
}