#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class DisjointSet {
 public:
  vector<int> parent, size;
  DisjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) parent[i] = i;
  }

  int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  };

  void unionBySize(int u, int v) {
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);
    if (ulp_u == ulp_v) return;

    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int newConnection(vector<vector<int>>& grid) {
  int n = grid.size();
  DisjointSet ds(n * n);

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        for (int d = 0; d < 4; ++d) {
          int nRow = i + dr[d];
          int nCol = j + dc[d];
          if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < n &&
              grid[nRow][nCol] == 1) {
            int u = i * n + j;
            int v = nRow * n + nCol;
            ds.unionBySize(u, v);
          }
        }
      }
    }
  }

  int maxSize = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      unordered_set<int> s;
      if (grid[i][j] == 0) {
        for (int d = 0; d < 4; ++d) {
          int nRow = i + dr[d];
          int nCol = j + dc[d];
          if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < n &&
              grid[nRow][nCol] == 1) {
            int v = nRow * n + nCol;
            s.insert(ds.findParent(v));
          }
        }
      }
      int cnt = 1;
      for (auto& it : s) {
        cnt += ds.size[it];
      }
      maxSize = max(maxSize, cnt+1);
    }
  }
  for(int cell = 0; cell<n*n; ++cell){
    maxSize = max(maxSize, ds.size[ds.findParent(cell)]);
  }
  return maxSize;
}

int main() {
  vector<vector<int>> grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

  int result = newConnection(grid);

  cout << "Largest island size after flipping one 0: " << result << endl;

  return 0;
}