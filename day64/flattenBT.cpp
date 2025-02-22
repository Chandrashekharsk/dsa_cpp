#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};


void flatten(TreeNode* root) {
  TreeNode* prev = nullptr;

  auto helper = [&](TreeNode* node, auto&& helperRef) -> void {
    if (!node) return;
    helperRef(node->right, helperRef);
    helperRef(node->left, helperRef);
    node->right = prev;
    node->left = nullptr;
    prev = node;
  };

  helper(root, helper);
}

void flatten2(TreeNode* root) {
  if (!root) return;

  TreeNode* curr = root;
  while (curr) {
    if (curr->left) {
      TreeNode* prev = curr->left;
      while (prev->right) {
        prev = prev->right;
      }
      prev->right = curr->right;
      curr->right = curr->left;
      curr->left = nullptr;
    }
    curr = curr->right;
  }
}

void printFlattenedTree(TreeNode* root) {
  TreeNode* curr = root;
  while (curr) {
    cout << curr->val << " ";
    curr = curr->right;
  }
  cout << endl;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  flatten2(root);
  printFlattenedTree(root);

  return 0;
}