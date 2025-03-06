// 207. Course Schedule
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canFinish(int nc, vector<vector<int>>& prereqs) {
    if (prereqs.size() == 0) return true;

    vector<vector<int>> adj(nc);
    for (auto& edge : prereqs) {
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> indegree(nc, 0);
    queue<int> q;
    int cnt = 0;

    for (auto& i : adj) {
      for (auto& neighbour : i) {
        ++indegree[neighbour];
      }
    }
    for (int i = 0; i < nc; ++i) {
      if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      ++cnt;

      for (auto& neighbour : adj[curr]) {
        --indegree[neighbour];
        if (indegree[neighbour] == 0) q.push(neighbour);
      }
    }
    return cnt == nc;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> prereqs1 = {{1, 0}, {2, 1}, {3, 2}};
  cout << "Test Case 1: "
       << (sol.canFinish(4, prereqs1) ? "Can Finish" : "Cannot Finish") << endl;

  vector<vector<int>> prereqs2 = {{1, 0}, {0, 1}};
  cout << "Test Case 2: "
       << (sol.canFinish(2, prereqs2) ? "Can Finish" : "Cannot Finish") << endl;

  vector<vector<int>> prereqs3 = {{1, 0}, {2, 1}, {3, 2}, {4, 3}};
  cout << "Test Case 3: "
       << (sol.canFinish(5, prereqs3) ? "Can Finish" : "Cannot Finish") << endl;

  vector<vector<int>> prereqs4 = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
  cout << "Test Case 4: "
       << (sol.canFinish(4, prereqs4) ? "Can Finish" : "Cannot Finish") << endl;

  return 0;
}