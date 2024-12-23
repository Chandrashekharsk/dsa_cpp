#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decimalToBinary(int num) {
  string str = "";
  while (num > 0) {
    if (num % 2 == 1)
      str += '1';
    else
      str += '0';
    num = num / 2;
  }
  reverse(str.begin(), str.end());
  return str;
}

int binaryToDecimal(string str) {
  reverse(str.begin(), str.end());
  int num = 0;
  for (int i = 0; i < str.size(); i++) {
    num += (int)(str[i] - '0') * (int)(pow(2, i));
  }
  return num;
}

int binaryToDecimal2(string str) {
  int num = 0, pow2 = 1;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '1') num += pow2;
    pow2 *= 2;
  }
  return num;
}

int main() {
  int num = 13;
  cout << decimalToBinary(num) << "\n";
  cout << binaryToDecimal(decimalToBinary(num)) << "\n";
  cout << binaryToDecimal2(decimalToBinary(num)) << "\n";

  return 0;
}