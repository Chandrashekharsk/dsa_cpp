// 110. Balanced Binary Tree
// 104. Maximum Depth of Binary Tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfsHeight(TreeNode* root) {
  if (root == nullptr) return 0;

  int lh = dfsHeight(root->left);
  if (lh == -1) return -1;  // If left subtree is unbalanced
  int rh = dfsHeight(root->right);
  if (rh == -1) return -1;          // If right subtree is unbalanced
  if (abs(lh - rh) > 1) return -1;  // If current node is unbalanced
  return max(lh, rh) + 1;
}

// Function to check if the tree is balanced
bool isBalancedBT(TreeNode* root) { return dfsHeight(root) != -1; }

int main() {
  // Creating a balanced tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "Is Balanced: " << (isBalancedBT(root) ? "Yes" : "No") << endl;

  // Creating an unbalanced tree
  TreeNode* unbalancedRoot = new TreeNode(1);
  unbalancedRoot->left = new TreeNode(2);
  unbalancedRoot->left->left = new TreeNode(3);
  unbalancedRoot->left->left->left = new TreeNode(4);

  cout << "Is Balanced: " << (isBalancedBT(unbalancedRoot) ? "Yes" : "No")
       << endl;

  return 0;
}
