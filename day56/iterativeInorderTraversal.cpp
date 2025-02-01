#include <iostream>
#include <stack>  // Required for stack
#include <vector>
using namespace std;

// Binary Tree Node Definition
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Iterative Preorder Traversal (Left-Root-Right)
vector<int> iterativeInorderTraversal(TreeNode* root) {
  vector<int> ans;
  if (root == nullptr) return ans;

  stack<TreeNode*> st;
  TreeNode* currNode = root;

  while (true) {
    if(currNode){
      st.push(currNode);
      currNode = currNode->left;
    }else{
      if(st.empty()) break;
      TreeNode* topNode = st.top();
      st.pop();
      ans.push_back(topNode->data);
      currNode = topNode->right;
    }
  }
  return ans;
}

int main() {
  // Creating a sample binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<int> result = iterativeInorderTraversal(root);

  cout << "Preorder Traversal: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
