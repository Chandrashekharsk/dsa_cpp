#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr) {};
};

// LEFT, ROOT, RIGHT
void inOrderTraversal(TreeNode* root){
  if(root == nullptr) return;
  inOrderTraversal(root->left);
  cout<< root->val<<" ";
  inOrderTraversal(root->right);
}

// ROOT, LEFT, RIGHT
void preOrderTraversal(TreeNode* root){
  if(root == nullptr) return;
  cout<< root->val<<" ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// LEFT, RIGHT, ROOT
void postOrderTraversal(TreeNode* root){
  if(root == nullptr) return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout<< root->val<<" ";
}

int main(){

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  inOrderTraversal(root);cout<<"\n";
  preOrderTraversal(root);cout<<"\n";
  postOrderTraversal(root);cout<<"\n";


  return 0;
}