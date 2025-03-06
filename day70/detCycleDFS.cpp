#include <iostream>
#include <vector>
using namespace std;

bool dfs(int row, int col, int parentRow, int parentCol, vector<int>& delRow, vector<int>& delCol,
         vector<vector<int>>& grid, vector<vector<int>>& vis) {
  int n = grid.size(), m = grid[0].size();
  vis[row][col] = 1; // Mark current cell as visited

  for (int d = 0; d < 8; ++d) {  // Use 'd' instead of 'i'
    int nRow = row + delRow[d];
    int nCol = col + delCol[d];

    if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m) {
      if (!vis[nRow][nCol]) {
        if (dfs(nRow, nCol, row, col, delRow, delCol, grid, vis)) return true;
      } else if (!(nRow == parentRow && nCol == parentCol)) {
        return true; // Cycle detected
      }
    }
  }
  return false;
}

bool detectACycle(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));

  vector<int> delRow = {-1, 1, 0, 0, -1, -1, 1, 1};
  vector<int> delCol = {0, 0, -1, 1, -1, 1, -1, 1};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j]) { // Start DFS from unvisited nodes
        if (dfs(i, j, -1, -1, delRow, delCol, grid, vis)) return true;
      }
    }
  }
  return false;
}

int main() {
  vector<vector<int>> grid = {{1, 2, 3}, {4, 1, 6}, {7, 8, 1}};

  bool result = detectACycle(grid);
  cout << "Cycle detected: " << (result ? "Yes" : "No") << endl;

  return 0;
}
