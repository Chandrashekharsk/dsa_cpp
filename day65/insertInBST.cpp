// 701. Insert into a Binary Search Tree
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void helper(TreeNode* root, int val){
  if(root->val>val){
    // search in left;
    if(root->left) helper(root->left, val);
    else{
      root->left = new TreeNode(val);
      return;
    }
  }else{
    // search in right;
    if(root->right) helper(root->right, val);
    else{
      root->right = new TreeNode(val);;
      return;
    }
  }
}

TreeNode* insertInBST(TreeNode* root, int val){
  if(!root) return new TreeNode(val);
  helper(root, val);
  return root;
}

TreeNode* insertInBST2(TreeNode* root, int val){
  if(!root) return new TreeNode(val);
  TreeNode* curr = root;
  while(curr){
    if(curr->val<= val){
      if(curr->right) curr = curr->right;
      else {
        curr->right = new TreeNode(val);
        break;
      }
    }else{
      if(curr->left) curr = curr->left;
      else{
        curr->left = new TreeNode(val);
        break;
      }
    }
  }
  return root;
}

void printInOrder(TreeNode* root) {
  if (root == nullptr) return;
  printInOrder(root->left);

  // Print root node value
  cout << root->val << " ";

  // Visit right subtree
  printInOrder(root->right);
}

int main(){
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  root->right = new TreeNode(10);
  root->right->left = new TreeNode(9);  
  root->right->right = new TreeNode(12);

  printInOrder(root);
  cout<<endl;

  // TreeNode* newRoot = insertInBST2(root, 2);
  // newRoot = insertInBST2(newRoot, 4);
  TreeNode* newRoot = insertInBST2(root, 2);
  newRoot = insertInBST2(newRoot, 4);

  printInOrder(newRoot);

  return 0;
}