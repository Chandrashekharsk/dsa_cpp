// 112. Path Sum
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

bool helper(TreeNode* root, int sum, int targetSum) {
  if(!root) return false;
  sum += root->val;
  // check curr node is leaf node or not if yes then return true or false;
  if(!root->left && !root->right) return sum == targetSum;

  return helper(root->left, sum, targetSum) || helper(root->right, sum, targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
  return helper(root, 0, targetSum);
}

// Function to create a test tree
TreeNode* createTestTree() {
  /*
      Example Tree:
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
  */
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->right->right = new TreeNode(1);

  return root;
}

int main() {
  TreeNode* root = createTestTree();

  int targetSum = 22;
  cout << "Has Path Sum " << targetSum << "? " << (hasPathSum(root, targetSum) ? "Yes" : "No") << endl;

  targetSum = 26;
  cout << "Has Path Sum " << targetSum << "? " << (hasPathSum(root, targetSum) ? "Yes" : "No") << endl;

  targetSum = 18;
  cout << "Has Path Sum " << targetSum << "? " << (hasPathSum(root, targetSum) ? "Yes" : "No") << endl;

  return 0;
}