// 67. Add Binary
#include <iostream>
#include <vector>
using namespace std;

string addBinary(string a, string b) {
  string ans = "";
  int i = a.size() - 1, j = b.size() - 1;
  int carry = 0, base = 2;

  while (i >= 0 || j >= 0) {
    int d1 = 0, d2 = 0, sum = 0;
    if (i >= 0) d1 = a[i--] - '0';
    if (j >= 0) d2 = b[j--] - '0';
    sum = d1 + d2 + carry;

    if (sum >= base) {
      carry = 1;
      sum -= base;
    } else carry = 0;
    ans = (char)(sum + '0') + ans;
  }
  if (carry) ans = '1' + ans;
  return ans;
}

int main() {
  // string a = "11", b = "1";
  // cout<< addBinary(a, b) << '\n'; // 100
  string a = "1010", b = "1011";
  cout << addBinary(a, b) << '\n';  // 10101

  return 0;
}