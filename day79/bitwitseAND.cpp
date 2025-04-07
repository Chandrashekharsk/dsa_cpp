// 201. Bitwise AND of Numbers Range
#include <iostream>
#include <vector>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
  int cnt = 0;
  while(left != right){
    ++cnt;
    right >>= 1;
    left >>= 1;
  }
  return left <<= cnt;
}

int main() {
  int left = 5, right = 7;  // Binary: 101, 110, 11
  cout << "Bitwise AND of range [" << left << ", " << right << "]: " << rangeBitwiseAnd(left, right) << endl;

  left = 0, right = 1;  // Binary: 0, 1
  cout << "Bitwise AND of range [" << left << ", " << right
       << "]: " << rangeBitwiseAnd(left, right) << endl;

  left = 10, right = 15;  // Binary: 1010 to 1111
  cout << "Bitwise AND of range [" << left << ", " << right
       << "]: " << rangeBitwiseAnd(left, right) << endl;

  return 0;
}