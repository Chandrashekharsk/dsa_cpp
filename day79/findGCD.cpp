// 1979. Find Greatest Common Divisor of Array
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  while (b) {
    int rem = a % b;
    cout<< "a: " << a << ", b: " << b << ", rem: " << rem << '\n';
    a = b;
    b = rem;
  }
  return a;
}

int main() {
  cout<<gcd(5, 2)<<'\n'; // 5
  // cout<<gcd(42, 24)<<'\n'; // 6

  return 0;
}