#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

vector<int> getInorder(TreeNode* root) {
  vector<int> inorder;
  if (!root) return {};
  TreeNode* curr = root;

  while (curr) {
    if (!curr->left) {
      inorder.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode* prev = curr->left;
      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }

      if (!prev->right) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = nullptr;
        inorder.push_back(curr->val);
        curr = curr->right;
      };
    };
  }
  return inorder;
}

vector<int> getPreorder(TreeNode* root) {
  vector<int> preorder;
  if (!root) return {};
  TreeNode* curr = root;

  while (curr) {
    if (!curr->left) {
      preorder.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode* prev = curr->left;
      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }

      if (!prev->right) {
        prev->right = curr;
        preorder.push_back(curr->val);
        curr = curr->left;
      } else {
        prev->right = nullptr;
        curr = curr->right;
      };
    };
  }
  return preorder;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);

  vector<int> inorder = getInorder(root);
  for (int val : inorder) {
    cout << val << " ";
  }
  cout << endl;
  vector<int> preorder = getPreorder(root);
  for (int val : preorder) {
    cout << val << " ";
  }
  cout << endl;
  
  return 0;
}