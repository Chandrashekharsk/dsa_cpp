#include <limits.h>  // For INT_MAX and INT_MIN
#include <iostream>
using namespace std;

int reverse(int x) {
  long long ans = 0;
  
  while (x != 0) {
    int lastDigit = x % 10;

    // for checking integer overflow
    if ((ans > INT_MAX / 10) ||(ans == INT_MAX / 10 && lastDigit > INT_MAX % 10)) return 0;
    if ((ans < INT_MIN / 10) ||(ans == INT_MIN / 10 && lastDigit < INT_MIN % 10)) return 0;

    ans = (ans * 10) + lastDigit;
    x /= 10;
  }
  return ans;
}
int main() {
  cout << reverse(123) << "\n";
  cout << reverse(1534236469) << "\n";  // Example to test overflow

  return 0;
}
