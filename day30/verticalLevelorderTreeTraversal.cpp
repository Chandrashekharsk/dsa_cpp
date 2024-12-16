#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode*, pair<int, int>>> todo;
  todo.push({root, {0, 0}});

  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    TreeNode* node = p.first;
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(node->val);

    if (node->left) {
      todo.push({node->left, {x - 1, y + 1}});
    }
    if (node->right) {
      todo.push({node->right, {x + 1, y + 1}});
    }
  }

  vector<vector<int>> ans;
  for (auto p : nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  
  return ans;
}


int main() { 



  return 0; 
}