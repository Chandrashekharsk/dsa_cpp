// 101. Symmetric Tree
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

bool isMirrored(TreeNode* left, TreeNode* right){
  if(!left || !right) return left == right;
  if(left->val != right->val) return false;
  return isMirrored(left->left, right->right) && isMirrored(left->right, right->left);
}

bool isSymmetrical(TreeNode* root){
  if(!root) return true;
  return isMirrored(root->left, root->right);
}
int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);

  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);

  cout << (isSymmetrical(root) ? "True" : "False") << endl;  // Output: True

  return 0;
}
