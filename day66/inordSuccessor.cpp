#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void inordSuccessorInBST(TreeNode* root, TreeNode* p, TreeNode*& res){
  if(!root) return;
  if(root->val<=p->val){
    return inordSuccessorInBST(root->right, p, res);
  }else{
    res = root;
    return inordSuccessorInBST(root->left, p, res);
  }
};

TreeNode* IOS(TreeNode* root, TreeNode* p){
  TreeNode* res = nullptr;
  inordSuccessorInBST(root, p, res);
  return res;
};

TreeNode* IOS2(TreeNode* root, TreeNode* p){
  TreeNode* curr = root;
  TreeNode* res = nullptr;
  while(curr){
    if(curr->val<=p->val){
      curr = curr->right;
    }else{
      res = curr;
      curr = curr->left;
    }
  }
  return res;
};


int main(){
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  root->right->right->right = new TreeNode(8);
  root->right->right->right->right = new TreeNode(9);

  cout<<IOS(root, root->right->right)->val<<endl;
  cout<<IOS2(root, root->right->right)->val<<endl;


  return 0;
}