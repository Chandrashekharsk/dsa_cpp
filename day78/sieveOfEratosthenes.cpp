// 204. Count Primes
#include <iostream>
#include <vector>
using namespace std;

void SOE(int n) {
  vector<int> primes(n+1, 0);
  

  for (int i = 2; i <= n; ++i) {
    if (!primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = 1;
      }
    }
  }

  for (int it=2; it<n+1; ++it) {
    if (!primes[it]) cout << it << " ";
  }
}

int main() {
  // Test cases for SOE
  cout << "Prime numbers up to 10: ";
  SOE(10);  // Expected: 2 3 5 7
  cout << endl;

  cout << "Prime numbers up to 20: ";
  SOE(20);  // Expected: 2 3 5 7 11 13 17 19
  cout << endl;

  cout << "Prime numbers up to 31: ";
  SOE(31);  // Expected: 2 3 5 7 11 13 17 19 23 29 31
  cout << endl;

  return 0;
}