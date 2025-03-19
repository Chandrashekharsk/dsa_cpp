#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
  vector<pair<int, int>> adj[n];
  const int mod = 1e9 + 7;  // Correct way to define a large constant

  for (auto& road : roads) {
    adj[road[0]].push_back({road[1], road[2]});
    adj[road[1]].push_back({road[0], road[2]});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
  vector<int> time(n, 1e9), ways(n, 0);
  pq.push({0, 0});
  time[0] = 0;
  ways[0] = 1;

  while (!pq.empty()) {
    auto [currTime, currNode] = pq.top();
    pq.pop();

    for (auto& [itNode, itTime] : adj[currNode]) {
      int newTime = currTime + itTime;

      if (newTime < time[itNode]) {
        pq.push({newTime, itNode});
        time[itNode] = newTime;
        ways[itNode] = ways[currNode] % mod;  
      } else if (newTime == time[itNode]) {
        ways[itNode] = (ways[itNode] + ways[currNode]) % mod; 
      }
    }
  }
  return ways[n - 1];
}

int main() {
  // Test Case 1: Basic Path Count Test
  vector<vector<int>> roads1 = {{0, 1, 2}, {1, 2, 3}, {0, 2, 5}};
  cout << "Test Case 1: " << countPaths(3, roads1) << " (Expected: 1)" << endl;

  // Test Case 2: Multiple Paths with Same Shortest Time
  vector<vector<int>> roads2 = {{0, 1, 1}, {1, 3, 1}, {0, 2, 1}, {2, 3, 1}};
  cout << "Test Case 2: " << countPaths(4, roads2) << " (Expected: 2)" << endl;

  // Test Case 3: Large Weights
  vector<vector<int>> roads3 = {{0, 1, 100000}, {1, 2, 200000}, {2, 3, 300000}};
  cout << "Test Case 3: " << countPaths(4, roads3) << " (Expected: 1)" << endl;

  // Test Case 4: Disconnected Graph
  vector<vector<int>> roads4 = {{0, 1, 5}, {1, 2, 10}};  // No edge to node 3
  cout << "Test Case 4: " << countPaths(4, roads4) << " (Expected: 0)" << endl;

  // Test Case 5: Fully Connected Graph with Different Paths
  vector<vector<int>> roads5 = {
      {0, 1, 1}, {0, 2, 1}, {1, 2, 1}, {1, 3, 2}, {2, 3, 2}};
  cout << "Test Case 5: " << countPaths(4, roads5) << " (Expected: 2)" << endl;

  return 0;
}
