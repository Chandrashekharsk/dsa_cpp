// 653. Two Sum IV - Input is a BST
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

class BSTIterator{
  private:
  stack<TreeNode*> st;
  bool reverse;

  void pushAll(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
      st.push(curr);
      if(!reverse) curr = curr->left;
      else curr = curr->right;
    }
  }

  public:
  BSTIterator(TreeNode* root, bool isReverse){
    reverse = isReverse;
    pushAll(root);
  }

  int next(){
    TreeNode* curr = st.top();
    st.pop();
    if(!reverse) pushAll(curr->right);
    else pushAll(curr->left);
    return curr->val;
  }

  bool hasNext(){
    return !st.empty();
  }
};

bool findTarget(TreeNode* root, int tar){
  if(!root) return false;
  BSTIterator l(root, false);
  BSTIterator r(root, true);
  int i = l.next(), j = r.next();
  
  while(i<j){
    int currSum = i+j;
    if(currSum==tar) return true;
    else if (currSum < tar) i = l.hasNext() ? l.next() : i;
    else j = r.hasNext() ? r.next() : j;
  }
  return false;
}

int main(){
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  cout<<findTarget(root, 69);
  cout<<findTarget(root, 9);
  

  return 0;
}