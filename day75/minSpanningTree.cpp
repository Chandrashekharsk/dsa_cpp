#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MSTEdgesSum(int V, vector<vector<int>> adj[]) {
  vector<int> vis(V, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  // Start from node 0
  pq.push({0, 0});
  int sum = 0;
  int edgesUsed = 0;  // Count the number of edges in the MST

  while (!pq.empty()) {
    auto [currDist, currNode] = pq.top();
    pq.pop();

    if (vis[currNode] == 1) continue;
    vis[currNode] = 1;
    sum += currDist;
    edgesUsed++;

    for (auto& it : adj[currNode]) {
      int node = it[0];
      int dist = it[1];
      if (!vis[node]) {
        pq.push({dist, node});
      }
    }
  }

  // If MST does not span all nodes, return -1 (Graph is disconnected)
  if (edgesUsed < V) return -1;
  
  return sum;
}

// ✅ Helper function to add an edge
void addEdge(vector<vector<int>> adj[], int u, int v, int weight) {
  adj[u].push_back({v, weight});
  adj[v].push_back({u, weight});  // Undirected graph
}

void testCases() {
  // ✅ Test Case 1: Basic Graph
  int V1 = 5;
  vector<vector<int>> adj1[V1];
  addEdge(adj1, 0, 1, 2);
  addEdge(adj1, 1, 2, 3);
  addEdge(adj1, 0, 3, 6);
  addEdge(adj1, 1, 3, 8);
  addEdge(adj1, 1, 4, 5);
  addEdge(adj1, 2, 4, 7);

  cout << "Test Case 1: " << MSTEdgesSum(V1, adj1) << " (Expected: 16)\n";

  // ✅ Test Case 2: Small Graph
  int V2 = 3;
  vector<vector<int>> adj2[V2];
  addEdge(adj2, 0, 1, 1);
  addEdge(adj2, 1, 2, 2);
  addEdge(adj2, 0, 2, 3);

  cout << "Test Case 2: " << MSTEdgesSum(V2, adj2) << " (Expected: 3)\n";

  // ✅ Test Case 3: Disconnected Graph
  int V3 = 4;
  vector<vector<int>> adj3[V3];
  addEdge(adj3, 0, 1, 1);
  addEdge(adj3, 2, 3, 2);  // No connection between {0,1} and {2,3}

  cout << "Test Case 3: " << MSTEdgesSum(V3, adj3) << " (Expected: -1)\n";

  // ✅ Test Case 4: Single Node (Trivial Case)
  int V4 = 1;
  vector<vector<int>> adj4[V4];

  cout << "Test Case 4: " << MSTEdgesSum(V4, adj4) << " (Expected: 0)\n";
}

int main() {
  testCases();
  return 0;
}
