#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string findOrder(string dict[], int N, int K) {
  vector<vector<int>> adj(K);
  vector<int> indegree(K, 0);
  string ans = "";
  queue<int> q;

  // Construct the graph
  for (int i = 0; i < N - 1; ++i) {
    string s1 = dict[i];
    string s2 = dict[i + 1];
    int len = min(s1.size(), s2.size());
    bool foundValid = false;

    for (int idx = 0; idx < len; ++idx) {
      if (s1[idx] != s2[idx]) {
        adj[s1[idx] - 'a'].push_back(s2[idx] - 'a');
        ++indegree[s2[idx] - 'a'];
        foundValid = true;
        break;
      }
    }
    // Edge case: invalid order if prefix comes later (e.g., "abc" before "ab")
    if (!foundValid && s1.size() > s2.size()) return "";
  }

  // Push all nodes with 0 indegree to the queue
  for (int i = 0; i < K; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  int cnt = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    ans += ((char)(curr + 'a'));
    ++cnt;

    for (auto& neighbour : adj[curr]) {
      --indegree[neighbour];
      if (indegree[neighbour]==0) q.push(neighbour);
    }
  }

  // If we couldn't process all characters, it means there's a cycle
  return (cnt == K) ? ans : "";
}

void runTestCases() {
  string dict1[] = {"baa", "abcd", "abca", "cab", "cad"};
  cout << "Order for dictionary 1: " << findOrder(dict1, 5, 4) << endl;
  
  string dict2[] = {"caa", "aaa", "aab"};
  cout << "Order for dictionary 2: " << findOrder(dict2, 3, 3) << endl;
  
  // string dict3[] = {"wrt", "wrf", "er", "ett", "rftt"};
  // cout << "Order for dictionary 3: " << findOrder(dict3, 5, 5) << endl;

  // Edge case: Only one word, no meaningful order
  string dict4[] = {"abc"};
  cout << "Order for dictionary 4: " << findOrder(dict4, 1, 3) << endl;

  // Edge case: No valid order (prefix before word)
  string dict5[] = {"abc", "ab"};
  cout << "Order for dictionary 5: " << findOrder(dict5, 2, 3) << endl;

  // Edge case: Cycle in order (e.g., "x" -> "y", "y" -> "x")
  string dict6[] = {"zx", "zy", "yx", "yz"};
  cout << "Order for dictionary 6: " << findOrder(dict6, 4, 4) << endl;
}

int main() {
  runTestCases();

  return 0;
}
