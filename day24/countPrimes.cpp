// 204. count primes
//Sieve of Erasthoenes
#include <cmath>  // for sqrt function
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
  if (n <= 2) return 0;
  vector<bool> primes(n, true);
  int count = 0;

  for (int i = 2; i < n; i++) {
    if (primes[i]) {
      count++;
      for (int j = static_cast<long long>(i) * i; j < n; j += i) {
        primes[j] = false;
      }
    }
  }
  return count;
}

int main() {
  cout << countPrimes(2)
       << "\n";  // Output should be 0 as there are no primes < 2
  cout << countPrimes(50) << "\n";  // Output the count of primes < 50

  return 0;
}
