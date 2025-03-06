// 1254. Number of Closed Islands
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countLands(vector<vector<int>> mat) {
  int n = mat.size(), m = mat[0].size();
  queue<pair<int, int>> q;
  vector<vector<int>> vis(n, vector<int>(m, 0));

  int delRow[] = {0, 0, -1, 1};
  int delCol[] = {-1, 1, 0, 0};

  // traverse boundaries and push them in queue
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(i==0 || j==0 || i==n-1 || j==m-1){
        if(mat[i][j]==1){
          vis[i][j] = 1;
          q.push({i, j});
        }
      }
    }
  }



  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow > 0 && nCol > 0 && nRow < n && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 1) {
        vis[nRow][nCol] = 1;
        q.push({nRow, nCol});
      }
    }
  }

  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (!vis[i][j] && mat[i][j] == 1) ++ans;
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> mat = {
      {1, 0, 1, 0},
      {0, 1, 0, 1}, 
      {0, 1, 1, 0}, 
      {0, 0, 0, 1},
      {0, 1, 0, 1},
    };

  int result = countLands(mat);
  cout << "Number of lands: " << result << endl;

  return 0;
}