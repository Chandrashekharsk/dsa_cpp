#include <iostream>
#include <vector>
using namespace std;

class DistjointSet {
  vector<int> size;

 public:
  vector<int> parent;
  DistjointSet(int n) {
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

int minEdgesReuiredToConnect(int n, vector<vector<int>>& edges) {
  DistjointSet ds(n);
  int extraEdges = 0, requiredEdges = 0;

  for (auto& edge : edges) {
    int node = edge[0];
    int adjNode = edge[1];
    if (ds.findParent(node) != ds.findParent(adjNode)) {
      // case: Not already connected
      ds.unionBySize(node, adjNode);
    } else {
      // case: Already connected
      ++extraEdges;
    }
  };
  int cntConComp = 0;
  for (int i = 0; i < n; ++i) {
    if (ds.parent[i] == i) ++cntConComp;
  }
  requiredEdges = cntConComp - 1;
  return (extraEdges >= requiredEdges) ? requiredEdges : -1;
}

int main() {
  int n = 6;  // Number of nodes
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 4}, {2, 3}, {4, 5}};

  int result = minEdgesReuiredToConnect(n, edges);
  if (result != -1) {
    cout
        << "The minimum number of edges required to connect all components is: "
        << result << endl;
  } else {
    cout << "It is not possible to connect all components with the given edges."
         << endl;
  }

  return 0;
}