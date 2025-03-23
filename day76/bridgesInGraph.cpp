#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int& timer, int parent, int steps[], int low[],
         vector<int>& vis, vector<vector<int>>& bridges, vector<int> adj[]) {
  vis[node] = 1;
  ++timer;
  steps[node] = low[node] = timer;

  for (auto& it : adj[node]) {
    if (it == parent) continue;

    if (!vis[it]) {
      dfs(it, timer, node, steps, low, vis, bridges, adj);
      low[node] = min(low[it], low[node]);
      // check is it a briedge
      if (low[it] > steps[node]) {
        bridges.push_back({node, it});
      }
    } else {
      low[node] = min(low[node], low[it]);
    }
  }
}

vector<vector<int>> criteriaConnections(int n,
                                        vector<vector<int>>& connections) {
  vector<int> adj[n];
  for (auto& it : connections) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  vector<int> vis(n, 0);
  vector<vector<int>> bridges;
  int steps[n];
  int low[n];
  int timer = 1;

  dfs(0, timer, -1, steps, low, vis, bridges, adj);
  return bridges;
}

int main() {
  int n = 5;
  vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

  vector<vector<int>> result = criteriaConnections(n, connections);

  cout << "Bridges in the graph:" << endl;
  for (auto& bridge : result) {
    cout << bridge[0] << " - " << bridge[1] << endl;
  }

  return 0;
}