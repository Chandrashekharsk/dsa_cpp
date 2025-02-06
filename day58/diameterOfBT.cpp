// 543. Diameter of Binary Tree
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfsHeight(TreeNode* root, int& maxi){
  if(root == nullptr) return 0;
  int lh = dfsHeight(root->left, maxi);
  int rh = dfsHeight(root->right, maxi);
  
  maxi = (maxi, lh+rh);
  return 1 + max(lh, rh);
}

int maxi = 0;
int diameterOfBT(TreeNode* root){
  if(root == nullptr) return 0;
  int maxi = 0;
  dfsHeight(root, maxi);
  return maxi;
}

int main(){

   // Creating a balanced tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "Diameter: " << diameterOfBT(root) << endl;

  // Creating an unbalanced tree
  TreeNode* unbalancedRoot = new TreeNode(1);
  unbalancedRoot->left = new TreeNode(2);
  unbalancedRoot->left->left = new TreeNode(3);
  unbalancedRoot->left->left->left = new TreeNode(4);

  cout << "Diameter2: " << diameterOfBT(unbalancedRoot)<<endl;

  return 0;
}