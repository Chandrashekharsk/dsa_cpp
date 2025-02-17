#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void csp(TreeNode* root){
  if(!root) return;
  int left = 0, right = 0;
  if(root->left) left = root->left->val;
  if(root->right) right = root->right->val;

  if(root->val < left + right) root->val = left+right;
  else{
    if(root->left) root->left->val = root->val;
    if(root->right) root->right->val = root->val;
  }

  csp(root->left);
  csp(root->right);

  int newLeft = 0, newRight = 0;
  if(left) newLeft = root->left->val;
  if(left) newRight = root->right->val;
  
  if(root->left || root->right) root->val = newLeft + newRight;
}

void preorderTrav(TreeNode* root){
  if(!root) return;
  cout<< root->val<<" ";
  preorderTrav(root->left);
  preorderTrav(root->right);
}

int main(){
  TreeNode * root = new TreeNode(40);

  root->left = new TreeNode(10);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(5);

  root->right = new TreeNode(20);
  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(40);
  preorderTrav(root);
  cout<<endl;
  csp(root);
  preorderTrav(root);
  cout<<endl;



  return 0;
}