#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int MaxDepth(TreeNode* root){
  if(root == nullptr) return 0;
  int maxi=0;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    for(int i=0; i<size; ++i){
      TreeNode* curr = q.front();
      q.pop();
      if(curr->left) q.push(curr->left);
      if(curr->right) q.push(curr->right);
    }
    ++maxi;
  }
  return maxi;
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