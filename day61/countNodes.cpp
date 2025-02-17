#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};


int heightOfLBT(TreeNode* root){
  if(!root) return 0;
  int height = 0;
  while(root){
    ++height;
    root = root->left;
  }
  return height;
};
int heightOfRBT(TreeNode* root){
  if(!root) return 0;
  int height = 0;
  while(root){
    ++height;
    root = root->right;
  }
  return height;
};

int countNodes(TreeNode* root){
  if(!root) return 0;

  int lh = heightOfLBT(root);
  int rh = heightOfRBT(root);
  if(lh == rh) return (1<<lh) - 1;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
//      3
//     / \
//    5   1
//   / \  / 
//  6   2 0  
  TreeNode* root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);


  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  

  cout<<countNodes(root);


  return 0;
}