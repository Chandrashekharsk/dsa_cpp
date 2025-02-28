#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

int floorInBST(TreeNode* root, int val){
  int ans = -1;
  while(root){
    if(root->val == val){
      return root->val;
    }else if(root->val<val){
      ans = root->val;
      root = root->right;
    }else{
      root = root->left;
    } 
  }
  return ans;
}

int main(){
  // Constructing BST
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  root->right = new TreeNode(10);
  root->right->left = new TreeNode(9);  
  root->right->right = new TreeNode(12);

  cout<<floorInBST(root, 13);
  
  return 0;
}