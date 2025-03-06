#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(int i, int j, int baseRow, int baseCol, vector<pair<int, int>>& vec, vector<int>& delRow, vector<int>& delCol,
  vector<vector<int>>& grid, vector<vector<int>>& vis){
  int n = grid.size(), m = grid[0].size();
  vec.push_back({i - baseRow, j - baseCol});
  vis[i][j] = 1;

  for(int d=0; d<4; ++d){
    int nrow = i + delRow[d];
    int ncol = j + delCol[d];
    if(nrow>0 && ncol>0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
      dfs(nrow, ncol, baseRow, baseCol, vec, delRow, delCol, grid, vis);
    }
  }
}

int cntDistIslands(vector<vector<int>>& grid){
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>>vis(n, vector<int>(m, 0));
  set<vector<pair<int,int>>> s;

  vector<int> delRow = {0, 0, -1, 1};
  vector<int> delCol = {-1, 1, 0, 0};

  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(!vis[i][j] && grid[i][j] == 1){
        vector<pair<int, int>> vec;
        dfs(i,j, i, j, vec, delRow, delCol, grid, vis);
        s.insert(vec);
      }
    }
  }
  return s.size();
}

int main(){
  vector<vector<int>> mat = {
    {1, 0, 1, 0},
    {0, 1, 0, 1}, 
    {0, 1, 1, 0}, 
    {0, 0, 0, 1},
    {0, 1, 0, 1},
  };

  int result = cntDistIslands(mat);
  cout << "Number of lands: " << result << endl;

  return 0;
}