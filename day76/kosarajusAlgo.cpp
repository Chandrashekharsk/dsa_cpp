#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
  vis[node] = 1;
  for (auto& it : adj[node]) {
    if (!vis[it]) dfs(it, vis, adj, st);
  }
  st.push(node);
}
void dfs2(int node, vector<int>& vis, vector<int> adj[]) {
  vis[node] = 1;
  for (auto& it : adj[node]) {
    if (!vis[it]) dfs2(it, vis, adj);
  }
}

int stronglyConnectedNodes(int V, vector<int> adj[]) {
  stack<int> st;
  vector<int> vis(V, 0);

  for (int i = 0; i < V; ++i) {
    if (!vis[i]) dfs(i, vis, adj, st);
  }
  // stack will contains top-bottom 0, 1, 2, 3, 4, 5, ..., V-1;

  vector<int> adjT[V];
  for (int i = 0; i < V; ++i) {
    vis[i] = 0;
    for (auto& it : adj[i]) {
      // reverse the edges and store it on new adjT
      adjT[it].push_back(i);
    }
  }

  int scc = 0;
  while (!st.empty()) {
    int currNode = st.top();
    st.pop();
    if (!vis[currNode]) {
      ++scc;
      dfs2(currNode, vis, adjT);
    }
  }
  return scc;
}

int main() {
  int V = 5;
  vector<int> adj[V];
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[1].push_back(3);
  adj[3].push_back(4);

  int result = stronglyConnectedNodes(V, adj);

  cout << "Number of strongly connected components: " << result << endl;

  return 0;
}