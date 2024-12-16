#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};


int maxSum(TreeNode* root, int & sum){
  if(root== nullptr) return 0;

  int leftSum = maxSum(root->left, sum);
  int rightSum = maxSum(root->left, sum);

  sum = max( sum, leftSum+ rightSum+ root->val);
  return root->val + max(leftSum, rightSum);
}

int maxPathSum (TreeNode* root){
  int sum = 0;
  maxSum(root, sum);
  return sum;
}


int main(){

  


  return 0;
}