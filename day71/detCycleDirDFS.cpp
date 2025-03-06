#include <iostream>
#include <vector>
using namespace std;


bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
  vis[node] = 2;   // Mark node as vis and pathVis(Current Stack)

  for (auto& neighbor : adj[node]) {
    if (!vis[neighbor]) {
      if (dfs(neighbor, adj, vis)) return true;  // Cycle detected
    } else if (vis[neighbor]==2) {
      return true;  // Found a back edge → Cycle detected
    }
  }

  vis[node] = 1;  // Remove node from recursion stack after processing
  return false;
}

bool detectCycle(int V, vector<vector<int>>& adj) {
  vector<int> vis(V, 0);

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (dfs(i, adj, vis)) return true;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> adj1 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {3},  // 2 -> 3
      {1}   // 3 -> 1 (cycle)
  };

  cout << (detectCycle(4, adj1) ? "Cycle Detected" : "No Cycle") << endl;

  vector<vector<int>> adj2 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {3},  // 2 -> 3
      {}    // 3 has no outgoing edge (no cycle)
  };

  cout << (detectCycle(4, adj2) ? "Cycle Detected" : "No Cycle") << endl;

  return 0;
}
