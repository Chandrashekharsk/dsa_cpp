#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

class NodeVal{
  public:
  int maxNodeVal, minNodeVal, maxSize;
  NodeVal(int minVal, int maxVal, int maxSize){
    this->minNodeVal = minVal;
    this->maxNodeVal = maxVal;
    this->maxSize = maxSize;
  }
};

NodeVal helper(TreeNode* root){
  if(!root) return NodeVal(INT_MAX, INT_MIN, 0);

  auto left = helper(root->left);
  auto right = helper(root->right);

  if(left.maxNodeVal<root->val && root->val<right.minNodeVal){
    // VALID BST FOUND
    return NodeVal(min(root->val, left.minNodeVal), max(root->val, right.maxNodeVal), 1+left.maxSize+right.maxSize);
  }
  // VALID BST NOT FOUND
  return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
};

int largestBST(TreeNode* root){
  return helper(root).maxSize;
}

int main(){
  TreeNode* root = new TreeNode(20);

  root->left = new TreeNode(15);
  root->left->left = new TreeNode(14);
  root->left->left->right = new TreeNode(17);
  root->left->right = new TreeNode(18);
  root->left->right->left = new TreeNode(16);
  root->left->right->right = new TreeNode(19);
  
  root->right = new TreeNode(40);
  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(60);
  root->right->right->left = new TreeNode(50);

  cout<<largestBST(root);


  return 0;
}