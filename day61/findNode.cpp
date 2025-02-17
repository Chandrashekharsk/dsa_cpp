#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

TreeNode* findNode(TreeNode* root, int tarVal) {
  if(!root) return root;
  if(root->val == tarVal) return root;
  
  
  TreeNode* left = findNode(root->left, tarVal);
  TreeNode* right = findNode(root->right, tarVal);
  return left ? left: right;
}

int main(){
  TreeNode* root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  TreeNode* res = findNode(root, 7);
  cout<< res->val;


  return 0;
}