#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sortestPath(vector<vector<int>>& edges, int N, int M, int src) {
  vector<vector<int>> adj(N);

  for (int i = 0; i < M; ++i) {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  };

  queue<pair<int, int>> q;
  vector<int> dist(N, 1e9);
  q.push({src, 0});
  dist[src] = 0;

  while (!q.empty()) {
    auto currVal = q.front().first;
    auto currDist = q.front().second;
    q.pop();

    for (auto& it : adj[currVal]) {
      if (dist[it] > 1 + currDist) {
        dist[it] = 1 + currDist;
        q.push({it, 1 + currDist});
      }
    };
  };
  for(int i=0; i<dist.size(); ++i){
    if(i == 1e9) dist[i] = -1;
  }
  return dist;
}

void printDistances(const vector<int>& dist) {
  for (int d : dist) {
    if (d == 1e9) {
      cout << "INF ";
    } else {
      cout << d << " ";
    }
  }
  cout << endl;
}

int main() {
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}};
  vector<int> result1 = sortestPath(edges1, 5, 6, 0);
  cout << "Shortest paths from node 0 in graph 1: ";
  printDistances(result1);

  vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  vector<int> result2 = sortestPath(edges2, 5, 4, 0);
  cout << "Shortest paths from node 0 in graph 2: ";
  printDistances(result2);

  vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}};
  vector<int> result3 = sortestPath(edges3, 6, 6, 0);
  cout << "Shortest paths from node 0 in graph 3: ";
  printDistances(result3);

  return 0;
}