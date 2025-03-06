// 802. Find Eventual Safe States
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// safe nodes are a part of path which doesn't have a cycle

// 0 → Unvisited
// 1 → Safe node (processed completely)
// 2 → Currently in recursion stack (detecting cycles)

bool dfs(int i, vector<vector<int>>& graph, vector<int>& ans,
         vector<int>& vis) {
  vis[i] = 2;

  for (auto& neighbour : graph[i]) {
    if (vis[neighbour] == 0) {
      if (dfs(neighbour, graph, ans, vis)) return true;
    } else if (vis[neighbour] == 2)
      return true;
  }

  vis[i] = 1;
  ans.push_back(i);
  return false;
}

vector<int> findSafeNodes(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<int> ans;
  vector<int> vis(n, 0);

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) dfs(i, graph, ans, vis);
  };
  sort(ans.begin(), ans.end());

  return ans;
}

int main() {
  vector<vector<int>> adj1 = {
      {1, 2},  // 0 -> 1, 0 -> 2
      {2, 3},  // 1 -> 2, 1 -> 3
      {5},     // 2 -> 5
      {0},     // 3 -> 0
      {5},     // 4 -> 5
      {},      // 5
      {}       // 6
  };
  vector<int> safeNodes1 = findSafeNodes(adj1);
  cout << "Test Case 1: ";
  for (int node : safeNodes1) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj2 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {3},  // 2 -> 3
      {4},  // 3 -> 4
      {}    // 4
  };
  vector<int> safeNodes2 = findSafeNodes(adj2);
  cout << "Test Case 2: ";
  for (int node : safeNodes2) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj3 = {
      {1, 2},  // 0 -> 1, 0 -> 2
      {2, 3},  // 1 -> 2, 1 -> 3
      {3},     // 2 -> 3
      {},      // 3
      {2, 3}   // 4 -> 2, 4 -> 3
  };
  vector<int> safeNodes3 = findSafeNodes(adj3);
  cout << "Test Case 3: ";
  for (int node : safeNodes3) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj4 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {0},  // 2 -> 0 (cycle)
      {4},  // 3 -> 4
      {}    // 4
  };
  vector<int> safeNodes4 = findSafeNodes(adj4);
  cout << "Test Case 4: ";
  for (int node : safeNodes4) cout << node << " ";
  cout << endl;

  return 0;
}