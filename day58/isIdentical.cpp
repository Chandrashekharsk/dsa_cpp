// 100. Same Tree
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isIdenticalTrees(TreeNode* root1, TreeNode* root2){
  if(root1 == nullptr || root2 == nullptr)  return root1 == root2;
  return root1->val == root2->val && isIdenticalTrees(root1->left, root2->left) && isIdenticalTrees(root1->right, root2->right);
}

int main(){

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(6);
  // root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(4);

  // Creating an unbalanced tree
  TreeNode* unbalancedRoot = new TreeNode(1);
  unbalancedRoot->left = new TreeNode(2);
  unbalancedRoot->left->left = new TreeNode(4);
  unbalancedRoot->left->left->left = new TreeNode(4);

  cout << "Is identical: " << (isIdenticalTrees(root, unbalancedRoot) ? "Yes" : "No")<< endl;

  return 0;
}