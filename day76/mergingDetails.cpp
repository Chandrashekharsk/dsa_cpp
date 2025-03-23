#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class DisjointSet {
  vector<int> size;
  vector<int> parent;

 public:
  DisjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
  };

  int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  }

  void unionBySize(int u, int v) {
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);
    if (ulp_u == ulp_v) return;

    int u_size = size[ulp_u];
    int v_size = size[ulp_v];
    if (u_size < v_size) {
      parent[ulp_u] = ulp_v;
      ++size[ulp_v];
    } else {
      parent[ulp_v] = ulp_u;
      ++size[ulp_u];
    }
  }
};

vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
  int n = details.size();
  DisjointSet ds(n);
  unordered_map<string, int> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < details[i].size(); ++j) {
      string currMail = details[i][j];

      if (m.find(currMail) == m.end()) {
        m[currMail] = i;
      } else {
        ds.unionBySize(i, m[currMail]);
      }
    }
  };

  vector<vector<string>> ans;
  vector<vector<string>> merged(n);
  for (auto& it : m) {
    string mail = it.first;
    int idx = it.second;
    merged[ds.findParent(idx)].push_back(mail);
  }

  for (int i = 0; i < n; ++i) {
    if (merged[i].size() == 0) continue;

    sort(merged[i].begin(), merged[i].end());
    vector<string> temp;
    temp.push_back(details[i][0]);
    for (auto& it : merged[i]) {
      temp.push_back(it);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main() {
  vector<vector<string>> details = {
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"John", "johnnybravo@mail.com"},
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"Mary", "mary@mail.com"}};

  vector<vector<string>> result = mergeDetails(details);

  for (const auto& account : result) {
    for (const auto& entry : account) {
      cout << entry << " ";
    }
    cout << endl;
  }

  return 0;
}