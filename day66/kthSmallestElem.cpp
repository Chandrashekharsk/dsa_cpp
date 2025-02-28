#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

void helper(TreeNode* root, int& k, int& result) {
  if (!root || k == 0) return;
  helper(root->left, k, result);
  --k;
  if (k == 0) {
    result = root->val;
    return;
  }
  helper(root->right, k, result);
}

int kthSmallestElem(TreeNode* root, int k) {
  int result = -1;
  helper(root, k, result);
  return result;
}

void morisTraversal(TreeNode* root, vector<int>& in, int& res, int& k){
  if(!root) return;
  TreeNode* curr = root;
  while(curr){
    if(curr->left){
      TreeNode* prev = curr->left;
      while(prev->right && prev->right != curr){
        prev = prev->right;
      }
      
      if(!prev->right){
        prev->right = curr;
        curr = curr->left;
      }else{
        prev->right = nullptr;
        in.push_back(curr->val);
        --k;
        if(k==0){
          res = curr->val;
          break;
        }
        curr = curr->right;
      }
    }else{
      in.push_back(curr->val);
      --k;
        if(k==0){
          res = curr->val;
          break;
        }
      curr = curr->right;
    }
  }
}

int kthSmallestElem2(TreeNode* root, int k){
  vector<int> in;
  int res = -1;
  morisTraversal(root, in, res, k);
  for(int i: in) cout<<i<<" ";
  cout<<endl;
  return res;
}


void printInOrder(TreeNode* root) {
  if (!root) return;
  printInOrder(root->left);
  cout << root->val << " ";
  printInOrder(root->right);
}

int main() {
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  printInOrder(root);
  cout << endl;

  // cout << "2nd smallest element: " << kthSmallestElem(root, 2) << endl;

  cout<<kthSmallestElem2(root, 4);

  return 0;
}