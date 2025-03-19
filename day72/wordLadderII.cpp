// 126. Word Ladder II
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<string>> worrdLadder2(string beginWord, string endWord, vector<string>& wordList) {
  vector<vector<string>> ans;
  unordered_set<string> s(wordList.begin(), wordList.end());
  vector<string> levelStrings;
  queue<vector<string>> q;
  if(!s.count(endWord)) return {};
  q.push({beginWord});
  levelStrings.push_back(beginWord);
  bool found = false;

  while (!q.empty() && !found) {
    int size = q.size();

    for (int it = 0; it < size; ++it) {
      auto currVec = q.front();
      q.pop();
      string word = currVec.back();

      if (word == endWord) {
        // currVec size will be always same for each vec of current level
        ans.push_back(currVec);
        found = true;
      }

      string tempString = word;

      for (int i = 0; i < word.size(); ++i) {
        char originalChar = tempString[i];

        for (char j = 'a'; j <= 'z'; ++j) {
          tempString[i] = j;

          if (s.count(tempString)) {
            vector<string> newVec = currVec;
            newVec.push_back(tempString);
            q.push(newVec);
            levelStrings.push_back(tempString);
          }
        }
        tempString[i] = originalChar;
      }

    }
    for (const auto& i : levelStrings) s.erase(i);
  }
  return ans;
}

void printLadders(const vector<vector<string>>& ladders) {
  for (const auto& ladder : ladders) {
    for (const auto& word : ladder) {
      cout << word << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
  vector<vector<string>> result1 = worrdLadder2("hit", "cog", wordList1);
  cout << "Ladders from 'hit' to 'cog' in word list 1:" << endl;
  printLadders(result1);

  vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
  vector<vector<string>> result2 = worrdLadder2("hit", "cog", wordList2);
  cout << "Ladders from 'hit' to 'cog' in word list 2:" << endl;
  printLadders(result2);

  vector<string> wordList3 = {"a", "b", "c"};
  vector<vector<string>> result3 = worrdLadder2("a", "c", wordList3);
  cout << "Ladders from 'a' to 'c' in word list 3:" << endl;
  printLadders(result3);

  return 0;
}