#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

string reverseName(string word) {
  unordered_set<char> s;
  string reversed;
  for (int i = 0; i < word.size(); ++i) {
    if (!s.count(word[i])) {
      reversed = word[i] + reversed;
    }
    s.insert(word[i]);
  }
  return reversed;
};


int main() {
  string word = "Chandrashekhar";
  cout << reverseName(word) << endl;
  cout << reverseName("thank you") << endl;

  return 0;
}