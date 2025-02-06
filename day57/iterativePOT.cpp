#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TreeNode definition
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Postorder Traversal (LEFT -> RIGHT -> ROOT)
vector<int> iterativePostorderTraversal(TreeNode* root) {
  vector<int> ans;
  if (!root) return ans;

  stack<TreeNode*> st1, st2;
  st1.push(root);

  while (!st1.empty()) {
    root = st1.top();
    st1.pop();
    st2.push(root);  // ✅ Fix: Store nodes in `st2` for reverse order

    if (root->left) st1.push(root->left);
    if (root->right) st1.push(root->right);
  }

  while (!st2.empty()) {
    ans.push_back(st2.top()->val);
    st2.pop();
  }
  return ans;
}

// Function to build a sample tree
TreeNode* buildSampleTree() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);
  return root;
}

int main() {
  TreeNode* root = buildSampleTree();

  vector<int> postorder = iterativePostorderTraversal(root);
  for (int val : postorder) cout << val << " ";
  cout << endl;                                

  return 0;
}
