#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstras(int V, vector<vector<int>> adj[], int src) {
  vector<int> dist(V, 1e9);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;  // minheap store pairs
  dist[src] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    int currDist = pq.top().first;
    int currNode = pq.top().second;
    pq.pop();

    for (auto& neighbour : adj[currNode]) {
      int neighbourNode = neighbour[0];
      int neighbourDist = neighbour[1];
      if (currDist + neighbourDist < dist[neighbourNode]) {
        dist[neighbourNode] = currDist + neighbourDist;
        pq.push({currDist + neighbourDist, neighbourNode});
      }
    }
  }

  return dist;
}

int main() {
  int V = 5;
  vector<vector<int>> adj[V];
  adj[0].push_back({1, 2});
  adj[0].push_back({4, 1});
  adj[1].push_back({2, 3});
  adj[2].push_back({3, 6});
  adj[4].push_back({2, 2});
  adj[4].push_back({3, 4});

  vector<int> distances = dijkstras(V, adj, 0);

  for (int i = 0; i < V; i++) {
    cout << "Distance from node 0 to node " << i << " is " << distances[i]
         << endl;
  }

  return 0;
}