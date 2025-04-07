#include <iostream>
#include <vector>
using namespace std;

vector<int> smallestPrimeFactorization(int n) {
  vector<int> spf(n + 1, 0);
  for (int i = 2; i <= n; ++i) spf[i] = i;

  for (int i = 2; i <= n; ++i) {
    if (spf[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  };

  vector<int> ans;
  while (n > 1) {
    ans.push_back(spf[n]);
    n /= spf[n];
  }
  return ans;
}

int main() {
  // Test cases for smallestPrimeFactorization
  int n1 = 12;
  vector<int> result1 = smallestPrimeFactorization(n1);
  cout << "Prime factorization of 12: ";
  for (int factor : result1) cout << factor << " ";  // Expected: 2 2 3
  cout << endl;

  int n2 = 30;
  vector<int> result2 = smallestPrimeFactorization(n2);
  cout << "Prime factorization of 30: ";
  for (int factor : result2) cout << factor << " ";  // Expected: 2 3 5
  cout << endl;

  int n3 = 17;
  vector<int> result3 = smallestPrimeFactorization(n3);
  cout << "Prime factorization of 17: ";
  for (int factor : result3) cout << factor << " ";  // Expected: 17
  cout << endl;

  return 0;
}