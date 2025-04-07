// 1123. Lowest Common Ancestor of Deepest Leaves
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

// Recursive DFS (Efficient & Clean)
TreeNode* findlcs(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL || root == p || root == q) return root;

  TreeNode* left = findlcs(root->left, p, q);
  TreeNode* right = findlcs(root->right, p, q);

  if (left && right) return root;
  return (left) ? left : right;
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
  if (!root) return root;
  queue<TreeNode*> q;
  q.push(root);

  vector<TreeNode*> level;
  while (!q.empty()) {
    level.clear();
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* curr = q.front();
      if (!curr->left && !curr->right) {
        level.push_back(curr);
      }
      q.pop();
      if (curr->left) {
        q.push(curr->left);
      }
      if (curr->right) {
        q.push(curr->right);
      }
    }
  }

  if (level.size() == 1) return level[0];

  TreeNode* first = level[0];
  TreeNode* last = level[level.size() - 1];

  return findlcs(root, first, last);
}

pair<TreeNode*, int> dfsLCS(TreeNode* root) {
  // {lcs, depth}
  if (!root) return {root, 0};
  auto left = dfsLCS(root->left);
  auto right = dfsLCS(root->right);

  if (left.second == right.second)  return {root, left.second + 1};
  else if (left.second > right.second) return {left.first, left.second + 1};
  else  return {right.first, right.second + 1};
}

TreeNode* lcaDeepestLeaves2(TreeNode* root) {
  pair<TreeNode*, int> result = dfsLCS(root);
  return result.first;
}

int main() {
  // Test Case 1: Original tree
  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);
  root1->right->right = new TreeNode(6);
  root1->left->left->left = new TreeNode(7);
  root1->left->left->right = new TreeNode(8);

  TreeNode* lca1 = lcaDeepestLeaves2(root1);
  cout << "Test Case 1 - LCA of deepest leaves: " << (lca1 ? lca1->val : -1)
       << endl;

  // Test Case 2: Single node tree
  TreeNode* root2 = new TreeNode(1);

  TreeNode* lca2 = lcaDeepestLeaves2(root2);
  cout << "Test Case 2 - LCA of deepest leaves: " << (lca2 ? lca2->val : -1)
       << endl;

  // Test Case 3: Tree with two leaves at the same depth
  TreeNode* root3 = new TreeNode(1);
  root3->left = new TreeNode(2);
  root3->right = new TreeNode(3);

  TreeNode* lca3 = lcaDeepestLeaves2(root3);
  cout << "Test Case 3 - LCA of deepest leaves: " << (lca3 ? lca3->val : -1)
       << endl;

  // Test Case 4: Tree with all nodes on one side
  TreeNode* root4 = new TreeNode(1);
  root4->left = new TreeNode(2);
  root4->left->left = new TreeNode(3);
  root4->left->left->left = new TreeNode(4);

  TreeNode* lca4 = lcaDeepestLeaves2(root4);
  cout << "Test Case 4 - LCA of deepest leaves: " << (lca4 ? lca4->val : -1)
       << endl;

  // Test Case 5: Empty tree
  TreeNode* root5 = nullptr;

  TreeNode* lca5 = lcaDeepestLeaves2(root5);
  cout << "Test Case 5 - LCA of deepest leaves: " << (lca5 ? lca5->val : -1)
       << endl;

  return 0;
}