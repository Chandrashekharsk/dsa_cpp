#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j1, int j2, vector<vector<int>>& grid,
           vector<vector<vector<int>>>& dp) {
  // Boundary check
  if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
    return -1e8;
  if (i == grid.size() - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }
  if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

  int maxi = -1e8;  // Initialize with a very small number

  for (int dj1 = -1; dj1 <= +1; dj1++) {
    for (int dj2 = -1; dj2 <= +1; dj2++) {
      int currVal = 0;
      if (j1 == j2)
        currVal = grid[i][j1];
      else
        currVal = grid[i][j1] + grid[i][j2];
      currVal += helper(i + 1, j1 + dj1, j2 + dj2, grid, dp);
      maxi = max(maxi, currVal);
    }
  }
  // Store the result in the memoization table
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
  return helper(0, 0, m - 1, grid, dp);
}

int maximumChocolates2(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else {
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
      }
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int maxi = -1e8;  // Initialize with a very small number

        for (int dj1 = -1; dj1 <= +1; dj1++) {
          for (int dj2 = -1; dj2 <= +1; dj2++) {

            int currVal = 0;
            if (j1 == j2) currVal = grid[i][j1];
            else currVal = grid[i][j1] + grid[i][j2];
            if(j1 + dj1 >=0  && j1 + dj1<m && j2 + dj2>=0 && j2 + dj2<m){
              currVal += dp[i + 1][j1 + dj1][j2 + dj2];
            }else currVal += -1e8;
            maxi = max(maxi, currVal);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }
  return dp[0][0][m-1];
}

int maximumChocolates3(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> next(m, vector<int>(m, 0));
  vector<vector<int>> curr(m, vector<int>(m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        next[j1][j2] = grid[n - 1][j1];
      else {
        next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
      }
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int maxi = -1e8;  // Initialize with a very small number

        for (int dj1 = -1; dj1 <= +1; dj1++) {
          for (int dj2 = -1; dj2 <= +1; dj2++) {

            int currVal = 0;
            if (j1 == j2) currVal = grid[i][j1];
            else currVal = grid[i][j1] + grid[i][j2];
            if(j1 + dj1 >=0  && j1 + dj1<m && j2 + dj2>=0 && j2 + dj2<m){
              currVal += next[j1 + dj1][j2 + dj2];
            }else currVal += -1e8;
            maxi = max(maxi, currVal);
          }
        }
        curr[j1][j2] = maxi;
      }
    }
    next = curr;
  }
  return next[0][m-1];
}

int main() {
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
  cout << maximumChocolates(grid)<<"\n";
  cout << maximumChocolates2(grid)<<"\n";
  cout << maximumChocolates3(grid)<<"\n";
  return 0;
}
