// 2551. Put Marbles in Bags
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long putMarbles(vector<int>& weights, int k) {
  int n = weights.size();
  if (k == 1) return 0;  // No partitions needed

  vector<int> pairSum(n - 1);
  for (int i = 0; i < n - 1; ++i) pairSum[i] = weights[i] + weights[i + 1];

  sort(pairSum.begin(), pairSum.end());

  long long minSum = 0, maxSum = 0;
  for (int i = 0; i < k - 1; ++i) {
    minSum += pairSum[i];
    maxSum += pairSum[n - 2 - i];
  }

  return maxSum - minSum;
}

void runTestCases() {
  vector<vector<int>> testCases = {
      {1, 3, 5, 1}, {4, 2, 3, 1}, {10, 20, 30, 40},
      {1, 1, 1, 1}, {5},          {7, 2, 9, 4, 1},
  };
  vector<int> kValues = {2, 2, 2, 2, 1, 3};

  for (int i = 0; i < testCases.size(); ++i) {
    cout << "Test Case " << i + 1 << ": ";
    cout << putMarbles(testCases[i], kValues[i]) << endl;
  }
}

int main() {
  runTestCases();
  return 0;
}
