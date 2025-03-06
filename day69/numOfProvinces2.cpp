// 547. Number of Provinces
#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
  vis[i] = 1;
  for (int j = 0; j < isConnected[i].size(); ++j) {
    if (i != j && isConnected[i][j] == 1 && !vis[j]) dfs(j, isConnected, vis);
  }
}

int findCircleNum(vector<vector<int>>& isConnected) {
  int n = isConnected.size();
  vector<int> vis(n, 0);
  int provinces = 0;

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      ++provinces;
      dfs(i, isConnected, vis);
    };
  }
  return provinces;
}

int main() {
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  int result = findCircleNum(isConnected);
  cout << "Number of provinces: " << result << endl;

  return 0;
}