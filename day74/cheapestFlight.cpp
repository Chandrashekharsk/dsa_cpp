#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cheapestFlight(int n, vector<vector<pair<int, int>>>& flights, int src,
                  int dst, int k) {
  vector<pair<int, int>> adj[n];

  for (auto edge : flights) {
    adj[edge[0]].push_back({edge[1], edge[2]});
  };

  //  stops, node, dist
  queue<pair<int, pair<int, int>>> q;
  vector<int> dist(n, 1e9);
  dist[src] = 0;
  q.push({0, {src, 0}});

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int currNode = curr.second.first;
    int currStop = curr.first;

    if (currStop > k) continue;

    for (auto neighbour : adj[curr]) {
      int neighbourNode = neighbour.first;
      int neighbourDist = neighbour.second;

      int newDist = dist[currNode] + neighbourDist;

      if (newDist < dist[neighbourNode] && currStop <= k) {
        dist[neighbourNode] = newDist;
        q.push({currStop + 1, {neighbourNode, newDist}});
      }
    }
  }
  return (dist[dst] == 1e9) ? -1 : dist[dst];
}

int main() { return 0; }