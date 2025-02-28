// 98. Validate Binary Search Tree
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

bool helper(TreeNode* root,  long long int lb, long long int ub){
  if(!root) return true;
  if(root->val<=lb || root->val>=ub) return false;
  return helper(root->left, lb, root->val) && helper(root->right, root->val, ub);
}

bool validBST(TreeNode* root) { 
  return helper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
  TreeNode* root = new TreeNode(5);

  root->left = new TreeNode(3);
  root->right = new TreeNode(6);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->right->right = new TreeNode(7);
  // root->right->left = new TreeNode(4);

  cout << validBST(root);

  return 0;
}