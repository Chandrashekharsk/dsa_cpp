// 124. Binary Tree Maximum Path Sum
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* root, int& MaxSum){
  if(root == nullptr) return 0;

  int ls = helper(root->left, MaxSum);
  int rs = helper(root->right, MaxSum);
  ls = ls>0? ls: 0;
  rs = rs>0? rs: 0;
  MaxSum = max(MaxSum, (root->val + ls+rs));
  return root->val + max(ls, rs);
}

int maxPathSum(TreeNode* root){
  int MaxSum = -1e9;
  helper(root, MaxSum);
  return MaxSum;
}

int main(){

  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(-1);
  // root->right = new TreeNode(20);

  // root->right->left = new TreeNode(15);
  // root->right->right = new TreeNode(7);

  cout << "MaxPathSum: " << maxPathSum(root) << endl;


  return 0;
}