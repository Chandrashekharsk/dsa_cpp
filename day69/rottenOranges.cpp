// 994. Rotting Oranges
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int rottenOranges(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  queue<pair<pair<int,int>,int>> q;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int maxTime = 0;
  int freshCnt = 0;

  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(grid[i][j]==2){
        q.push({{i, j}, 0});
        vis[i][j] = 2;
      }
      if(grid[i][j]==1) ++freshCnt;
    }
  }

  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};
  
  while(!q.empty()){
    int row = q.front().first.first;
    int col = q.front().first.second;
    int time = q.front().second;
    q.pop();
    maxTime = max(maxTime, time);
    
    for(int i=0; i<4; ++i){
      int nRow = row+delRow[i];
      int nCol = col+delCol[i];
      if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && vis[nRow][nCol] == 0 && grid[nRow][nCol]==1){
        --freshCnt;
        vis[nRow][nCol] = 2;
        q.push({{nRow, nCol}, time+1});
      }
    }
  }
  if(freshCnt>0) return -1;
  return maxTime;
}

int main() { 
  vector<vector<int>> grid = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}
};
  cout<<rottenOranges(grid);

  return 0; 
}