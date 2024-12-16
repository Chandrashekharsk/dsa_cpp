// 443. string compresson
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
  int ansIdx = 0, i = 0;
  while (i < chars.size()) {
    char currChar = chars[i];
    int count = 0;

    while (i < chars.size() && chars[i] == currChar) {
      count++;
      i++;
    }

    chars[ansIdx++] = currChar;
    if (count > 1) {
      for (char c : to_string(count)) chars[ansIdx++] = c;
    }
  }

  return ansIdx;
}
int main() {
  vector<char> vec = {'a', 'a', 'a', 'a', 'b', 'c', 'c', 'd'};
  int length = compress(vec);

  for (int i = 0; i < length; i++) {
    cout << vec[i] << " ";
  }
  cout << "\nLength of compressed string: " << length << endl;
  return 0;
}
