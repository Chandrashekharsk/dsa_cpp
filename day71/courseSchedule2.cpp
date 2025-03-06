// 210. Course Schedule II
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& preqs) {
    vector<int> ans;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    queue<int> q;

    // Build adjacency list and in-degree array
    for (auto& edge : preqs) {
      adj[edge[1]].push_back(edge[0]);
      ++indegree[edge[0]];
    }

    // Push all courses with zero in-degree
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) q.push(i);
    }

    // Process courses using Kahn's Algorithm
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      ans.push_back(curr);

      for (auto& neighbour : adj[curr]) {
        --indegree[neighbour];
        if (indegree[neighbour] == 0) q.push(neighbour);
      }
    }

    // If cycle exists (not all courses included), return empty vector
    return (ans.size() == n) ? ans : vector<int>();
  }
};

// Test function
void runTests() {
  Solution sol;

  vector<vector<int>> test1 = {{1, 0}};
  vector<vector<int>> test2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<vector<int>> test3 = {{1, 0}, {0, 1}};  // Cycle case
  vector<vector<int>> test4 = {};                // No prerequisites

  vector<int> res1 = sol.findOrder(2, test1);
  vector<int> res2 = sol.findOrder(4, test2);
  vector<int> res3 = sol.findOrder(2, test3);
  vector<int> res4 = sol.findOrder(1, test4);

  cout << "Test 1: ";
  for (int x : res1) cout << x << " ";
  cout << endl;
  cout << "Test 2: ";
  for (int x : res2) cout << x << " ";
  cout << endl;
  cout << "Test 3 (Cycle Case): ";
  for (int x : res3) cout << x << " ";
  cout << endl;
  cout << "Test 4 (No Prereqs): ";
  for (int x : res4) cout << x << " ";
  cout << endl;
}

// Main function
int main() {
  runTests();
  return 0;
}
