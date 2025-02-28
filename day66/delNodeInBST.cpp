// 450. Delete Node in a BST
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

TreeNode* helper(TreeNode* root) {
  if (!root->left)
    return root->right;
  else if (!root->right)
    return root->left;
  else{
    TreeNode* rightChild = root->right;
    TreeNode* leftChild = root->left;
    while (leftChild->right) {
      // go at right most node of left child
      leftChild = leftChild->right;
    }
    leftChild->right = rightChild;
    return root->left;
  }
}

TreeNode* delNode(TreeNode* root, int val) {
  if (!root) return root;
  if (root->val == val) return helper(root);

  TreeNode* curr = root;
  while (curr) {
    if (curr->val > val) {
      if (curr->left && curr->left->val == val) {
        curr->left = helper(curr->left);
      }
      curr = curr->left;
    } else {
      if (curr->right && curr->right->val == val) {
        curr->right = helper(curr->right);
      }
      curr = curr->right;
    }
  };
  return root;
}

void printInOrder(TreeNode* root) {
  if (!root) return;
  printInOrder(root->left);
  cout << root->val << " ";
  printInOrder(root->right);
}

int main() {
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  cout << "Original tree (in-order): ";
  printInOrder(root);
  cout << endl;

  root = delNode(root, 3);

  cout << "Tree after deleting node 3 (in-order): ";
  printInOrder(root);
  cout << endl;

  // Clean up memory
  // ...code to delete all nodes...

  return 0;
}