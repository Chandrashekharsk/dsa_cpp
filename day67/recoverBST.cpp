// 99. Recover Binary Search Tree
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void inorder (TreeNode* root, TreeNode*& first, TreeNode*& mid, TreeNode*& last, TreeNode*& prev){
  if(!root) return;
  inorder(root->left, first, mid, last, prev);

  if(prev && (root->val<prev->val)){
    if(!first){
      first = prev;
      mid = root;
    }else last = root;
  }
  prev = root;

  inorder(root->right, first, mid, last, prev);
}

void recoverBST(TreeNode* root){
  TreeNode* first = nullptr;
  TreeNode* mid = nullptr;
  TreeNode* last = nullptr;
  TreeNode* prev = nullptr;

  inorder(root, first, mid, last, prev);
  if(first && last) swap(first->val, last->val);
  else swap(first->val, mid->val);
}

void printInord(TreeNode* root){
  if(!root) return;
  printInord(root->left);
  cout<<root->val<<" ";
  printInord(root->right);
}


int main(){

  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(7);
  printInord(root);cout<<endl;
  recoverBST(root);
  printInord(root);cout<<endl;
  



  return 0;
}