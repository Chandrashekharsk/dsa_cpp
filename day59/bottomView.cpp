#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

vector<int> bottomView(TreeNode* root) {
  if (!root) return {};
  map<int, int> m;
  queue<pair<TreeNode*, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    int x = curr.second;
    m[x] = curr.first->val;

    if (curr.first->left) q.push({curr.first->left, x - 1});
    if (curr.first->right) q.push({curr.first->right, x + 1});
  }

  vector<int> ans;
  for (auto& i : m) {
    ans.push_back(i.second);
  }
  return ans;
}

int main() {
  // Sample Binary Tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);

  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  /*
            1
           / \
          2   3
         / \  /\
        4   56  7
                /
               8
  */

  auto result = bottomView(root);

  cout << "bottom view Traversal:\n";
  for (auto& i : result) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}