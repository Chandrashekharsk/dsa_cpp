#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int row, int col, vector<int>& delRow, vector<int>& delCol, vector<vector<int>>& grid, vector<vector<int>>& vis){
  int n = grid.size(), m = grid[0].size();
  queue<pair<pair<int, int>,int>> q;

  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(grid[i][j] == 1 && !vis[i][j]){
        vis[i][j] = 1;
        q.push({{i,j}, 0});
      }
    }
  }
  while(!q.empty()){
    int r = q.front().first.first;
    int c = q.front().first.second;
    int d = q.front().second;
    q.pop();
    grid[r][c] = d;

    for(int i=0; i<4; ++i){
      int nRow = r + delRow[i];
      int nCol = c + delCol[i];
      if(nRow>=0 && nCol >= 0 && nRow<n && nCol<m && !vis[nRow][nCol]){
        vis[nRow][nCol] = 1;
        q.push({ {nRow, nCol}, d+1});
      };
    };
  };
}

vector<vector<int>> distanceNearestOne(vector<vector<int>>& grid){
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>>vis(n, vector<int> (m, 0));

  vector<int> delRow = {0, 0, -1, 1};
  vector<int> delCol = { -1, 1, 0, 0};

  bfs(0, 0, delRow, delCol, grid, vis);
  return grid;
}

int main(){
  vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}};

  for(auto& i: distanceNearestOne(grid)){
    for(auto& j: i) cout<< j<<" ";
    cout<<endl;
  }
  cout<<endl;

  return 0;
}