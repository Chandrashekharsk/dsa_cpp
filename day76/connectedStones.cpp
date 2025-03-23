#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class DisjointSet {
  vector<int> size, parent;

 public:
  DisjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) parent[i] = i;
  }
  int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  }
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

int connectedStones(vector<vector<int>> stones, int n) {
  int mxRow = 0;
  int mxCol = 0;
  for (auto& it : stones) {
    mxRow = max(mxRow, it[0]);
    mxCol = max(mxCol, it[1]);
  }
  DisjointSet ds(mxRow * mxCol + 1);
  unordered_set<int> s;  // row, col+mxRow+1

  for (auto& it : stones) {
    int cr = it[0];
    int cc = it[1] + mxRow + 1;
    ds.unionBySize(cr, cc);
    s.insert(cr);
    s.insert(cc);
  }

  int comps = 0;
  for (auto& it : s) {
    if (ds.findParent(it) == it) ++comps;
  }
  return n - comps;  // here n == total true set coordinates
}

int main() {
  vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  int n = stones.size();

  int result = connectedStones(stones, n);

  cout << "Maximum number of stones that can be removed: " << result << endl;

  return 0;
}