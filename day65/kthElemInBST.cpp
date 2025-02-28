// 230. Kth Smallest Element in a BST
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

void inOrder(TreeNode* root, vector<int>& ans){
  if(!root) return;
  inOrder(root->left, ans);
  ans.push_back(root->val);
  inOrder(root->right, ans);
}

int kthSmallestElem(TreeNode* root, int k){
  vector<int> in;
  inOrder(root, in);
  if(k<1 || k>in.size()) return -1;
  return in[--k];
}

int main(){
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  root->right = new TreeNode(10);
  root->right->left = new TreeNode(9);  
  root->right->right = new TreeNode(12);

  cout<<kthSmallestElem(root, 2);
  cout<<kthSmallestElem(root, 9);

  return 0;
}