// 130. Surrounded Regions
#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<int>& delRow, vector<int>& delCol,
  vector<vector<char>>& mat, vector<vector<int>>& vis) {
    
  int n = mat.size(), m = mat[0].size();

  vis[row][col] = 1;

  for (int i = 0; i < 4; ++i) {
    int nRow = row + delRow[i];
    int nCol = col + delCol[i];
    if (nRow > 0 && nCol > 0 && nRow < n && nCol < m && !vis[nRow][nCol] &&
        mat[nRow][nCol] == 'O') {
      vis[nRow][nCol] = 1;
      dfs(nRow, nCol, delRow, delCol, mat, vis);
    }
  }
}

vector<vector<char>> replaceOsWithXs(vector<vector<char>> mat) {
  int n = mat.size(), m = mat[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));

  vector<int> delRow = {0, 0, -1, 1};
  vector<int> delCol = {-1, 1, 0, 0};

  for (int j = 0; j < m; ++j) {
    // first row
    if (!vis[0][j] && mat[0][j] == 'O') {
      dfs(0, j, delRow, delCol, mat, vis);
    }
    // last row
    if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
      dfs(n - 1, j, delRow, delCol, mat, vis);
    }
  }
  for (int i = 0; i < n; ++i) {
    // first col
    if (!vis[i][0] && mat[i][0] == 'O') {
      dfs(i, 0, delRow, delCol, mat, vis);
    }
    // last col
    if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
      dfs(i, m - 1, delRow, delCol, mat, vis);
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
    }
  }
  return mat;
}

int main() {
  vector<vector<char>> mat = {{'X', 'O', 'X', 'X'},
                              {'O', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'O'},
                              {'O', 'X', 'O', 'X'}};

  vector<vector<char>> result = replaceOsWithXs(mat);

  cout << "Resultant matrix:" << endl;
  for (const auto& row : result) {
    for (const auto& cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }

  return 0;
}