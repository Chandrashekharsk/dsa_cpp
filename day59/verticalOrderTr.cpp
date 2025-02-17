// 987. Vertical Order Traversal of a Binary Tree
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalOrderTrav(TreeNode* root) {
  if (!root) return {{}};  

  map<int, map<int, multiset<int>>> nodes;   // Stores nodes by vertical & level
  queue<pair<TreeNode*, pair<int, int>>> q;  // Queue for BFS traversal
  q.push({root, {0, 0}});                    // Root node at (x:0, y:0)

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    TreeNode* currNode = curr.first;
    int x = curr.second.first;   // Vertical position
    int y = curr.second.second;  // Level position

    nodes[x][y].insert(currNode->val);  // Insert node value at (x, y)

    if (currNode->left) q.push({currNode->left, {x - 1, y + 1}});
    if (currNode->right) q.push({currNode->right, {x + 1, y + 1}});
  }

  vector<vector<int>> ans;
  for (auto& x : nodes) {
    vector<int> cols;
    for (auto& y : x.second) {
      cols.insert(cols.end(), y.second.begin(), y.second.end());
    }
    ans.push_back(cols);
  }
  return ans;
}

int main() {
  // Sample Binary Tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->right->left = new TreeNode(8);

  /*
            1
           / \
          2   3
         / \  /\
        4   56  7
                /
               8
  */

  vector<vector<int>> result = verticalOrderTrav(root);

  cout << "Vertical Order Traversal:\n";
  for (auto& cols : result) {
    for (int val : cols) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
