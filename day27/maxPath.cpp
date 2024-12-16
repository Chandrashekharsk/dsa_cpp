#include <algorithm>  // For max function
#include <climits>    // For INT_MIN
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

int heightOfTreeNode(TreeNode* root, int& diameter) {
  if (root == nullptr) return 0;

  int lh = heightOfTreeNode(root->left, diameter);   
  int rh = heightOfTreeNode(root->right, diameter);  

  diameter = max(diameter, lh + rh);
  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
  int diameter = 0;
  heightOfTreeNode(root, diameter);
  return diameter;
}

int main() {
  //        1
  //       / \
  //      2   3
  //     / \ / \
  //    4  5 6  7
  //   /
  //  8
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left =
      new TreeNode(8);  // Add more depth for testing diameter

  // Calculate and display the diameter of the tree
  cout << "Diameter of the binary tree is: " << diameterOfBinaryTree(root)
       << endl;

  return 0;
}
