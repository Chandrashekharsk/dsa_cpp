#include <iostream>
#include <vector>
using namespace std;

int main() {
  char c1 = 'A';         // ASCII value: 65
  char c2 = 'B';         // ASCII value: 66
  int result = c1 + c2;  // result = 65 + 66 = 131
  cout << result<<"\n";

  string s = "Path";
  char c = 'U';
  string result2 = s + c;  // "PathU"
  cout<<result2<<"\n";

  return 0;
}