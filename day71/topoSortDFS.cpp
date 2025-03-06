#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Required DAG (directed acyclic graph)

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
  vis[i] = 1;

  for (auto& neighbour : adj[i]) {
    if (!vis[neighbour]) {
      dfs(neighbour, adj, vis, st);
    }
  };
  st.push(i);
};

vector<int> topoSort(int V, vector<vector<int>>& adj) {
  vector<int> vis(V, 0);
  vector<int> ans;
  stack<int> st;

  for (int i = 0; i < V; ++i) {
    if (!vis[i]) dfs(i, adj, vis, st);
  }

  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
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
  vector<int> topoOrder1 = topoSort(4, adj1);
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
  vector<int> topoOrder2 = topoSort(5, adj2);
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
  vector<int> topoOrder3 = topoSort(5, adj3);
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
  vector<int> topoOrder4 = topoSort(5, adj4);
  cout << "Test Case 4: ";
  for (int node : topoOrder4) cout << node << " ";
  cout << endl;

  return 0;
}