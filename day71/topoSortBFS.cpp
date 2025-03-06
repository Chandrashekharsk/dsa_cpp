#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Required DAG (directed acyclic graph)
// Kahn's Algorithm

vector<int> topoSortBFS(int V, vector<vector<int>>& adj) {
  vector<int> indegree(V, 0);
  vector<int> ans;
  queue<int> q;

  for (int i = 0; i < V; ++i) {
    for (auto& neighbour : adj[i]) {
      ++indegree[neighbour];
    };
  };

  for (int i = 0; i < V; ++i) {
    if (indegree[i] == 0) q.push(i);
  };

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    ans.push_back(curr);

    for (auto& neighbour : adj[curr]) {
      --indegree[neighbour];
      if (indegree[neighbour] == 0) q.push(neighbour);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> adj1 = {
      {1, 2},  // 0 -> 1, 0 -> 2
      {3},     // 1 -> 3
      {3},     // 2 -> 3
      {}       // 3
  };
  vector<int> topoOrder1 = topoSortBFS(4, adj1);
  cout << "Test Case 1: ";
  for (int node : topoOrder1) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj2 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {3},  // 2 -> 3
      {4},  // 3 -> 4
      {}    // 4
  };
  vector<int> topoOrder2 = topoSortBFS(5, adj2);
  cout << "Test Case 2: ";
  for (int node : topoOrder2) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj3 = {
      {1, 2},  // 0 -> 1, 0 -> 2
      {3},     // 1 -> 3
      {3},     // 2 -> 3
      {4},     // 3 -> 4
      {}       // 4
  };
  vector<int> topoOrder3 = topoSortBFS(5, adj3);
  cout << "Test Case 3: ";
  for (int node : topoOrder3) cout << node << " ";
  cout << endl;

  vector<vector<int>> adj4 = {
      {1},  // 0 -> 1
      {2},  // 1 -> 2
      {3},  // 2 -> 3
      {},   // 3
      {2}   // 4 -> 2
  };
  vector<int> topoOrder4 = topoSortBFS(5, adj4);
  cout << "Test Case 4: ";
  for (int node : topoOrder4) cout << node << " ";
  cout << endl;

  return 0;
}