#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode* root) {
  return (root->left == nullptr && root->right == nullptr);
}

void addLeftBoundary(TreeNode* root, vector<int>& ans) {
  TreeNode* curr = root->left;
  while (curr) {
    if (!isLeaf(curr)) ans.push_back(curr->val);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void addLeaves(TreeNode* root, vector<int>& ans) {
  if (isLeaf(root)) {
    ans.push_back(root->val);
    return;
  }
  if (root->left) addLeaves(root->left, ans);
  if (root->right) addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode* root, vector<int>& ans) {
  TreeNode* curr = root->right;
  vector<int> temp;
  while (curr) {
    if (!isLeaf(curr)) temp.push_back(curr->val);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  for (int i = temp.size() - 1; i >= 0; --i) ans.push_back(temp[i]);
}

vector<int> boundaryTraversal(TreeNode* root) {
  vector<int> ans;
  if (root == nullptr) return ans;
  if (!isLeaf(root)) ans.push_back(root->val);
  addLeftBoundary(root, ans);
  addLeaves(root, ans);
  addRightBoundary(root, ans);
  return ans;
}

int main() {
  //     1
  //    / \
    //   2   3
  //  / \  / \
    // 4  5 6   7
  //   / \
    //  8   9
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->right->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);

  vector<int> boundary = boundaryTraversal(root);
  cout << "Boundary traversal: ";
  for (int val : boundary) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
