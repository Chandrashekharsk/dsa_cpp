// 733. Flood Fill
#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, int initVal, int newVal, int rowSize, int colSize, vector<vector<int>>& newgrid, vector<vector<int>>& vis){
  // move orthogonally
  int dRow[] = {0, 0, 1, -1};
  int dCol[] = {-1, 1, 0, 0};
  vis[row][col] = 1;
  newgrid[row][col] = newVal;

  for(int i=0; i<4; ++i){
    int nRow = row+dRow[i];
    int nCol = col+dCol[i];
    if(nRow>=0 && nRow<rowSize && nCol>=0 && nCol<colSize 
      && !vis[nRow][nCol] && newgrid[nRow][nCol] == initVal){
        vis[nRow][nCol] = 1;
        dfs(nRow, nCol, initVal, newVal, rowSize, colSize, newgrid, vis);
    }
  }
}

vector<vector<int>> floodFill(int sr, int sc, int newVal, vector<vector<int>> grid){
  int r = grid.size(), c = grid[0].size();
  vector<vector<int>> vis(r, vector<int> (c, 0));

  dfs(sr, sc, grid[sr][sc], newVal, r, c, grid, vis);
  return grid;
}

int main(){
  vector<vector<int>> grid = {
    {1,1,1}, {1,1,0}, {1,0,1}
  };
  // for(int i = 0; i<grid.size(); ++i){
  //   for(int j = 0; j<grid[i].size(); ++j){
  //     cout<<grid[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  vector<vector<int>> res = floodFill(2, 0, 2, grid);
  for(int i = 0; i<res.size(); ++i){
    for(int j = 0; j<res[i].size(); ++j){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}