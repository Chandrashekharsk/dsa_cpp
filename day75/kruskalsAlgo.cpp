#include <algorithm>
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
  }
  void unionBySize(int u, int v) {
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    int u_size = size[ulp_u];
    int v_size = size[ulp_v];

    if (u_size < v_size) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else if (u_size > v_size) {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    } else {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
  }
};

int MST(int V, vector<vector<int>> adj[]) {
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < V; ++i) {
    for (auto& it : adj[i]) {
      int adjNode = it[0];
      int weight = it[1];
      int node = i;

      edges.push_back({weight, {node, adjNode}});
    }
  }

  sort(edges.begin(), edges.end());

  DistjointSet ds(V);
  int totWt = 0;

  for (auto& edge : edges) {
    int node = edge.second.first;
    int adjNode = edge.second.second;
    int weight = edge.first;

    if (ds.findParent(node) != ds.findParent(adjNode)) {
      // Not the part of same graph component
      totWt += weight;
      ds.unionBySize(node, adjNode);
    }
  }

  return totWt;
}

int main() {
  int V = 4;  // Number of vertices
  vector<vector<int>> adj[V];

  // Adding edges to the adjacency list
  adj[0].push_back({1, 10});  // Edge 0-1 with weight 10
  adj[0].push_back({2, 6});   // Edge 0-2 with weight 6
  adj[0].push_back({3, 5});   // Edge 0-3 with weight 5
  adj[1].push_back({0, 10});  // Edge 1-0 with weight 10
  adj[1].push_back({3, 15});  // Edge 1-3 with weight 15
  adj[2].push_back({0, 6});   // Edge 2-0 with weight 6
  adj[2].push_back({3, 4});   // Edge 2-3 with weight 4
  adj[3].push_back({0, 5});   // Edge 3-0 with weight 5
  adj[3].push_back({1, 15});  // Edge 3-1 with weight 15
  adj[3].push_back({2, 4});   // Edge 3-2 with weight 4

  int mstWeight = MST(V, adj);
  cout << "The weight of the Minimum Spanning Tree is: " << mstWeight << endl;

  return 0;
}
