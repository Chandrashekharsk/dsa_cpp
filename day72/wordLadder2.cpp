// 126. Word Ladder II
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void dfs(string& beginWord, string word, vector<string>& seq,
         unordered_map<string, int>& m, vector<vector<string>>& ans) {
  if (word == beginWord) {
    reverse(seq.begin(), seq.end());
    ans.push_back(seq);
    reverse(seq.begin(), seq.end());
    return;
  }

  string newWord = word;
  for (int i = 0; i < word.size(); ++i) {
    char originalChar = newWord[i];
    for (char j = 'a'; j <= 'z'; ++j) {
      newWord[i] = j;
      if (m.count(newWord) && m[newWord] + 1 == m[word]) {
        seq.push_back(newWord);
        dfs(beginWord, newWord, seq, m, ans);
        seq.pop_back();
      }
    }
    newWord[i] = originalChar;
  };
}

vector<vector<string>> worrdLadder2(string beginWord, string endWord,
                                    vector<string>& wordList) {
  unordered_set<string> s(wordList.begin(), wordList.end());
  vector<vector<string>> ans;
  if (!s.count(endWord)) return ans;
  unordered_map<string, int> m;
  queue<string> q;
  q.push(beginWord);
  s.erase(beginWord);
  m[beginWord] = 1;
  bool found = false;

  while (!q.empty() && !found) {
    int size = q.size();
    unordered_set<string> levelSet; 

    for (int it = 0; it < size; ++it) {
      string word = q.front();
      q.pop();
      int steps = m[word];

      if (word == endWord) found = true;

      for (int i = 0; i < word.size(); ++i) {
        char originalChar = word[i];
        for (char j = 'a'; j <= 'z'; ++j) {
          word[i] = j;

          if (s.count(word)) {
            q.push(word);
            levelSet.insert(word);
            m[word] = steps + 1;
          }
        }
        word[i] = originalChar;
      }
    };
    for(auto& w: levelSet) s.erase(w);
  };

  vector<string> sequence;
  sequence.push_back(endWord);
  dfs(beginWord, endWord, sequence, m, ans);
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