#include <iostream>
#include <vector>
using namespace std;

bool helper(int i, int j, int expectedVal, vector<vector<int>>& grid) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] != expectedVal) return false;
  if( expectedVal == (grid.size()*grid.size())-1) return true;

  int prev = grid[i][j];
  grid[i][j] = -1;
  int a = helper(i - 2, j - 1, expectedVal + 1, grid);
  int b = helper(i - 2, j + 1, expectedVal + 1, grid);
  int c = helper(i - 1, j - 2, expectedVal + 1, grid);
  int d = helper(i + 1, j - 2, expectedVal + 1, grid);
  int e = helper(i + 2, j - 1, expectedVal + 1, grid);
  int f = helper(i + 2, j + 1, expectedVal + 1, grid);
  int g = helper(i - 1, j + 2, expectedVal + 1, grid);
  int h = helper(i + 1, j + 2, expectedVal + 1, grid);
  grid[i][j] = prev;
  return a || b || c || d || e || f || g || h;
}

bool checkValidGrid(vector<vector<int>>& grid) {
  return helper(0, 0, 0, grid); 
}

int main() {
  // vector<vector<int>> grid = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
  vector<vector<int>> grid = {
    {0, 17, 4, 19, 6},
    {3, 22, 15, 8, 13},
    {16, 1, 18, 5, 20},
    {23, 2, 21, 14, 7},
    {10, 9, 12, 11, 24}
  };
  
  cout << checkValidGrid(grid) << "\n";

  return 0;
}