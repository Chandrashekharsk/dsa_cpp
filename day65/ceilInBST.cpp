#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

TreeNode* ceilInBST(TreeNode* root, int val) {
  TreeNode* res = nullptr;
  while (root != nullptr) {
    if (root->val == val) {
      return root;
    } else if (root->val < val) {
      root = root->right;
    } else {
      res = root;
      root = root->left;
    }
  }
  return res;
}

int main() {
  // Constructing BST
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  root->right = new TreeNode(10);
  root->right->left = new TreeNode(9);  
  root->right->right = new TreeNode(12);

  TreeNode* res = ceilInBST(root, 11);

  if (res) {
    cout << res->val << endl;
  } else {
    cout<< " does not exist in the BST." << endl;
  }

  return 0;
}
