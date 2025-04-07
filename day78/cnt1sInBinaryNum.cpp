#include <iostream>
#include <vector>
using namespace std;

int cnt1sInBinaryNum(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt += (n & 1);  
    n >>= 1;         
  }
  return cnt;
}

// efficient way to count 1s in binary number
// Brian Kernighan's Algorithm
// It works by repeatedly flipping the least significant 1 bit of n to 0
int cnt1sInBinaryNumber(int n) {
  int cnt = 0;
  while (n > 0) {
    ++cnt;
    n &= (n - 1);
  }
  return cnt;
}

int main() {
  // Test cases for cnt1sInBinaryNum
  cout << "Testing cnt1sInBinaryNum:" << endl;
  cout << "cnt1sInBinaryNum(5): " << cnt1sInBinaryNum(5) << " (Expected: 2)" << endl;
  cout << "cnt1sInBinaryNum(7): " << cnt1sInBinaryNum(7) << " (Expected: 3)" << endl;
  cout << "cnt1sInBinaryNum(0): " << cnt1sInBinaryNum(0) << " (Expected: 0)" << endl;

  // Test cases for cnt1sInBinaryNumber
  cout << "\nTesting cnt1sInBinaryNumber:" << endl;
  cout << "cnt1sInBinaryNumber(5): " << cnt1sInBinaryNumber(5) << " (Expected: 2)" << endl;
  cout << "cnt1sInBinaryNumber(7): " << cnt1sInBinaryNumber(7) << " (Expected: 3)" << endl;
  cout << "cnt1sInBinaryNumber(0): " << cnt1sInBinaryNumber(0) << " (Expected: 0)" << endl;

  return 0;
}