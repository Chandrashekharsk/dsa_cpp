// 200. Number of Islands
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int r, int c, vector<int>& delRow, vector<int>& delCol, vector<vector<char>>& grid){
  int n = grid.size(), m = grid[0].size();
  queue<pair<int, int>> q;
  q.push({r, c});

  while(!q.empty()){
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for(int i=0; i<4; ++i){
          int nRow = r + delRow[i];
          int nCol = c + delCol[i];
          if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && grid[nRow][nCol]=='1'){
              grid[nRow][nCol] = '0';
              q.push({nRow, nCol});
          }
      }
  }
};

int numIslands(vector<vector<char>>& grid) {
  int n = grid.size(), m = grid[0].size();
  int cnt = 0;

  // Define 8 possible directions: orthogonally & diagonally
  // int delRow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
  // int delCol[] = {0, 0, -1, 1, -1, 1, -1, 1};

  // Define 4 possible directions: orthogonally
  vector<int> delRow = {-1, 1, 0, 0};
  vector<int> delCol = {0, 0, -1, 1};

  for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
          if(grid[i][j] == '1'){
              ++cnt;
              grid[i][j] = '0';
              bfs(i, j, delRow, delCol, grid);
          }
      }
  }
  return cnt;
}


int main(){
// 1  1  0
// 1  1  0
// 0  0  1
  vector<vector<char>> isIsland = {{'1','1', '0'}, {'1','1','0'}, {'0','0','1'}};

  int result = numIslands(isIsland);
  cout << "Number of islands: " << result << endl;
  


  return 0;
}