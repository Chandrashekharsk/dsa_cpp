// 3502. Minimum Cost to Reach Every Position
#include <iostream>
#include <vector>
using namespace std;

vector<int> minCosts(vector<int>& cost) {
  int n = cost.size();
  vector<int> ans(n, 0);
  ans[0] = cost[0];
  for (int i = 1; i < n; ++i) {
    ans[i] = min(ans[i - 1], cost[i]);
  }
  return ans;
}

int main() {
  vector<int> cost = {10, 15, 20, 5, 30};
  vector<int> result = minCosts(cost);

  cout << "Minimum costs: ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}