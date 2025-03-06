#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int i, int j, vector<int>& delRow, vector<int>& delCol,
         vector<vector<int>>& grid, vector<vector<int>>& vis) {
  int n = grid.size(), m = grid[0].size();
  queue<pair<pair<int, int>, pair<int, int>>> q;  // {{row, col}, {parent_row, parent_col}}
  q.push({{i, j}, {-1, -1}});
  vis[i][j] = 1;

  while (!q.empty()) {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int parentRow = q.front().second.first;
    int parentCol = q.front().second.second;
    q.pop();

    for (int d = 0; d < 8; ++d) {
      int nRow = row + delRow[d];
      int nCol = col + delCol[d];

      if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m) {  // check valid index 
        if (!vis[nRow][nCol]) {
          vis[nRow][nCol] = 1;
          q.push({{nRow, nCol}, {row, col}});
        } else if (!(nRow == parentRow && nCol == parentCol)) {
          return true;  // Cycle detected
        }
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
      if (!vis[i][j]) {
        if (bfs(i, j, delRow, delCol, grid, vis)) return true;
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
