// 144. Binary Tree Preorder Traversal
//  94. Binary Tree Inorder Traversal
//  145. Binary Tree Postorder Traversal
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void postOrder_helper(TreeNode* root, vector<int>& ans){
  if(root == nullptr) return;
  postOrder_helper(root->left, ans);
  postOrder_helper(root->right, ans);
  ans.push_back(root->val);
}
// LEFT, RIGHT, ROOT
vector<int> postOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  postOrder_helper(root, ans);
  return ans;
};


void inOrder_helper(TreeNode* root, vector<int>& ans){
  if(root == nullptr) return;
  inOrder_helper(root->left, ans);
  ans.push_back(root->val);
  inOrder_helper(root->right, ans);
}
// LEFT, ROOT, RIGHT
vector<int> inOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  inOrder_helper(root, ans);
  return ans;
};


void preOrder_helper(TreeNode* root, vector<int>& ans){
  if(root == nullptr) return;
  ans.push_back(root->val);
  preOrder_helper(root->left, ans);
  preOrder_helper(root->right, ans);
}
// ROOT, LEFT, RIGHT
vector<int> preOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  preOrder_helper(root, ans);
  return ans;
};


int main(){

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  for(auto i: preOrderTraversal(root)) cout<< i<<" ";
  cout<<"\n";
  for(auto i: inOrderTraversal(root)) cout<< i<<" ";
  cout<<"\n";
  for(auto i: postOrderTraversal(root)) cout<< i<<" ";
  cout<<"\n";

  return 0;
}