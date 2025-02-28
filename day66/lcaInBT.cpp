#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

TreeNode* lca(TreeNode* root, int left, int right){
  if(!root || root->val==left || root->val == right) return root;
  TreeNode* lval  = lca(root->left, left, right);
  TreeNode* rval  = lca(root->right, left, right);
  if(lval && rval) return root;
  return lval? lval: rval;
}

int main(){
//     5
//    / \
//   3   6
//  / \    \
// 2   4    7
//      \
//       8
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(7);

  cout<<lca(root, 3, 8)->val;
  cout << endl;
  


  return 0;
}