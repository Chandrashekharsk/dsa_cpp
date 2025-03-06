#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<int>& color) {
  queue<int> q;
  q.push(start);
  color[start] = 0;  // Start with color 0

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto& neighbor : adj[node]) {
      if (color[neighbor] == -1) {
        color[neighbor] = !color[node];  // Assign opposite color
        q.push(neighbor);
      } else if (color[neighbor] == color[node]) {
        return false;  // Found same color on adjacent nodes
      }
    }
  }
  return true;
}

bool checkBipartite(int V, vector<vector<int>>& adj) {
  vector<int> color(V, -1);  // -1 means uncolored

  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      if (!bfs(i, adj, color)) return false;
    }
  }
  return true;
}

int main() {
  vector<vector<int>> adj1 = {
      {1, 3},  // 0 - 1, 0 - 3
      {0, 2},  // 1 - 0, 1 - 2
      {1, 3},  // 2 - 1, 2 - 3
      {0, 2}   // 3 - 0, 3 - 2
  };

  cout << (checkBipartite(4, adj1) ? "Bipartite" : "Not Bipartite") << endl;

  vector<vector<int>> adj2 = {
      {1, 2, 3},  // 0 - 1, 0 - 2, 0 - 3
      {0, 2},     // 1 - 0, 1 - 2
      {0, 1},     // 2 - 0, 2 - 1
      {0}         // 3 - 0
  };

  cout << (checkBipartite(4, adj2) ? "Bipartite" : "Not Bipartite") << endl;

  return 0;
}
