// 1008. Construct Binary Search Tree from Preorder Traversal
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

TreeNode* helper(int& i, int bound, vector<int>& preorder) {
  if (i >= preorder.size() || preorder[i] > bound) return nullptr;
  TreeNode* root = new TreeNode(preorder[i++]);
  root->left = helper(i, root->val, preorder);
  root->right = helper(i, bound, preorder);
  return root;
}

TreeNode* buildBST(vector<int>& preorder) {
  int i = 0;
  return helper(i, INT_MAX, preorder);
}

void printInOrder(TreeNode* root) {
  if (!root) return;
  printInOrder(root->left);
  cout << root->val << " ";
  printInOrder(root->right);
}

int main() {
  vector<int> preorder = {8, 5, 1, 7, 10, 12};
  TreeNode* root = buildBST(preorder);

  cout << "Constructed tree (in-order): ";
  printInOrder(root);
  cout << endl;

  return 0;
}