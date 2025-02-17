// 236. Lowest Common Ancestor of a Binary Tree
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root == p || root == q) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left && right) return root; // If both left and right subtrees contain one node each
  return left ? left : right; // Otherwise, return the non-null side
}

int main() {
  // Constructing the tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(7);

  // Assigning p and q to existing tree nodes
  TreeNode* p = root->left->left;  // Node 4
  TreeNode* q = root->left->right; // Node 5

  TreeNode* res = lowestCommonAncestor(root, p, q);
  if (res) cout << "Lowest Common Ancestor: " << res->val << endl;
  else cout << "No Common Ancestor Found!" << endl;

  return 0;
}
