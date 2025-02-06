#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int MaxDepth(TreeNode* root){
  if(root == nullptr) return 0;

  int leftHeight = MaxDepth(root->left);
  int rightHeight = MaxDepth(root->right);

  return 1 + max(leftHeight, rightHeight);
}

int main(){
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(5);
  cout<<MaxDepth(root)<<endl;

  return 0;
}