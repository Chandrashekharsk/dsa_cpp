// 127. Word Ladder
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int findDistance(string startWord, string endWord, vector<string>& wordList) {
  unordered_set<string> s(wordList.begin(), wordList.end());
  queue<pair<string, int>> q;

  q.push({startWord, 1});
  s.erase(startWord);

  while (!q.empty()) {
    string curr = q.front().first;
    int currDist = q.front().second;
    q.pop();
    if (curr == endWord) return currDist;

    for (int i = 0; i < curr.size(); ++i) {
      string tempStr = curr;
      for (char j = 'a'; j <= 'z'; ++j) {
        tempStr[i] = j;
        if (s.count(tempStr)) {
          q.push({tempStr, 1 + currDist});
          s.erase(tempStr);
        }
      }
    }
  }
  return 0;
}

int main() {
  vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
  int result1 = findDistance("hit", "cog", wordList1);
  cout << "Distance from 'hit' to 'cog' in word list 1: " << result1 << endl;

  vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
  int result2 = findDistance("hit", "cog", wordList2);
  cout << "Distance from 'hit' to 'cog' in word list 2: " << result2 << endl;

  vector<string> wordList3 = {"a", "b", "c"};
  int result3 = findDistance("a", "c", wordList3);
  cout << "Distance from 'a' to 'c' in word list 3: " << result3 << endl;

  return 0;
}