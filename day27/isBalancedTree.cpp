#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

int depthOfTreeNode(TreeNode* root) {
  if (root == nullptr) return 0;

  int lh = depthOfTreeNode(root->left);
  if (lh == -1) return -1;
  int rh = depthOfTreeNode(root->right);
  if (rh == -1) return -1;

  if (abs(lh - rh) > 1) return -1;
  return (1 + max(lh, rh));
}

bool isBalancedTreeNode(TreeNode* root) {
  return (depthOfTreeNode(root) != -1); 
}

int main() {
  // Create a test tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Test if the tree is balanced
  if (isBalancedTreeNode(root)) {
    cout << "The tree is balanced!" << endl;
  } else {
    cout << "The tree is not balanced!" << endl;
  }

  return 0;
}