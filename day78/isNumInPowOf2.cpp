#include <iostream>
#include <vector>
using namespace std;

bool isNumInPowOf2(int n) {
  if (n == 0) return false;
  return (n & (n - 1)) == 0 ? true : false;
}

int main() {
  // Test cases for isNumInPowOf2
  cout << "Testing isNumInPowOf2:" << endl;
  cout << "isNumInPowOf2(0): " << isNumInPowOf2(0) << " (Expected: 0)" << endl;
  cout << "isNumInPowOf2(1): " << isNumInPowOf2(1) << " (Expected: 1)" << endl;
  cout << "isNumInPowOf2(2): " << isNumInPowOf2(2) << " (Expected: 1)" << endl;
  cout << "isNumInPowOf2(3): " << isNumInPowOf2(3) << " (Expected: 0)" << endl;
  cout << "isNumInPowOf2(4): " << isNumInPowOf2(4) << " (Expected: 1)" << endl;

  return 0;
}