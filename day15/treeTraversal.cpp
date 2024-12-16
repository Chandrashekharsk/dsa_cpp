#include<iostream>
#include<vector>
using namespace std;

// Definition of TreeNode
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

// ROOT, LEFT, RIGHT
void preOrderTraversal(TreeNode* root) {
  if (root == nullptr) return;
  
  cout << root->val << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// LEFT, ROOT, RIGHT
void inOrderTraversal(TreeNode* root) {
  if (root == nullptr) return;
  
  inOrderTraversal(root->left);
  cout << root->val << " ";
  inOrderTraversal(root->right);
}

// LEFT, RIGHT, ROOT
void postOrderTraversal(TreeNode* root) {
  if (root == nullptr) return;
  
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->val << " ";
}

int main(){

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  // Preorder traversal of the tree
  cout << "Inorder Traversal:";
  inOrderTraversal(root);
  // cout << "\nPreorder Traversal: ";
  // preOrderTraversal(root);
  // cout << "\nPost Traversal: ";
  // postOrderTraversal(root);

  return 0;
}