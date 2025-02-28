// 700. Search in a Binary Search Tree
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

// TreeNode* searchBST(TreeNode* root, int val){
//   while(root!=nullptr && root->val!=val){
//     root = root->val<val ? root->right : root->left;
//   }
//   return root;
// }

TreeNode* searchBST(TreeNode* root, int val) {
  TreeNode* curr = root;
  while(curr){
      if(curr->val == val){
          return curr;
      }else if(curr->val<val){
          curr = curr->right;
      }else{
          curr = curr->left;
      }
  }
  return curr;
}

int main(){
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);

  auto res = searchBST(root, 46);
  if(res) cout<< res->val<<endl;
  else cout<<" Not found";

  return 0;
}