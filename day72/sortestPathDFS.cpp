#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// only working for DAG(directed acyclic graph)

void topoDFS(int i, int vis[], vector<pair<int, int>> adj[], stack<int>& st) {
  vis[i] = 1;
  for (auto& neighbour : adj[i]) {
    int v = neighbour.first;
    if (!vis[v]) {
      topoDFS(v, vis, adj, st);
    }
  }
  st.push(i);
};

vector<int> findSortest(int N, int M, vector<int> edges[]) {
  vector<pair<int, int>> adj[N];

  for (int i = 0; i < M; ++i) {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v, wt});
  };
  for (auto& i : adj) {
    for (auto& j : i) {
      cout << j.first << " " << j.second << " ";
      cout << endl;
    }
  }

  stack<int> st;
  int vis[N] = {0};

  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      topoDFS(i, vis, adj, st);
    };
  };

  vector<int> dist(N, 1e9);
  // dist[st.top()] = 0;
  dist[0] = 0;
  while (!st.empty()) {
    int curr = st.top();
    int currWt = dist[curr];
    st.pop();

    if(dist[curr] != 1e9){
      for (auto& it : adj[curr]) {
        int nodeVal = it.first;
        int nodeWt = it.second;
        if (currWt + nodeWt < dist[nodeVal]) dist[nodeVal] = currWt + nodeWt;
      }
    }
  }
  return dist;
}

int main() {
  int N = 6, M = 7;
  vector<int> edges[] = {{0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {2, 3, 6}, {4, 2, 2}, {4, 5, 4}, {5, 3, 1}};
  vector<int> shortestDistances = findSortest(N, M, edges);

  cout << "Shortest distances from node 0:\n";
  for (int i = 0; i < N; i++) {
    if (shortestDistances[i] == 1e9) cout << "Node " << i << ": Unreachable\n";
    else cout << "Node " << i << ": " << shortestDistances[i] << "\n";
  }

  return 0;
}