// 1175. Prime Arrangements
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long int factorial(int n) {
  long long int ans = 1;
  for (int i = 2; i <= n; ++i) {
    ans = (ans * i) % MOD;
  }
  return ans;
}

int countPrimes(int n){
  vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false; 

  for (int i = 2; i * i <= n; ++i) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }

  int primeCnt = 0;
  for (auto& it : primes) {
    if(it) ++primeCnt;
  }
  
  return primeCnt;
}

int primeArrangements(int n) {
  int primeCnt = countPrimes(n);
  long long int ans = factorial(primeCnt) * factorial(n - primeCnt);
  return ans % MOD;
}

int main() { return 0; }