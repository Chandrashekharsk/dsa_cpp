#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class DistjointSet {
  vector<int> size;
  vector<int> parent;

 public:
  DistjointSet(int n) {
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

    int u_size = size[ulp_u];
    int v_size = size[ulp_v];

    if (u_size < v_size) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
  DistjointSet ds(n * m);
  int vis[n][m];
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  vector<int> ans;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (auto& it : operators) {
    int row = it[0];
    int col = it[1];
    if (vis[row][col] == 1) {
      ans.push_back(cnt);
      continue;
    }

    ++cnt;
    vis[row][col] = 1;

    for (int i = 0; i < 4; ++i) {
      int nRow = row + dr[i];
      int nCol = col + dc[i];
      if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && vis[nRow][nCol] == 1) {
        int u = row * m + col;
        int v = nRow * m + nCol;
        if (ds.findParent(u) != ds.findParent(v)) {
          --cnt;
          ds.unionBySize(u, v);
        }
      }
    }
    ans.push_back(cnt);
  }

  return ans;
}

int main() {
  int n = 3, m = 3;
  vector<vector<int>> operators = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}};

  vector<int> result = numOfIslands(n, m, operators);

  for (int count : result) {
    cout << count << " ";
  }
  cout << endl;

  return 0;
}