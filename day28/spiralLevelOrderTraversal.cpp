#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition of TreeNode structure
struct TreeNode {
  int val;          // Value of the node
  TreeNode* left;   // Pointer to the left child
  TreeNode* right;  // Pointer to the right child

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> zigZagTraversal(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == nullptr) return ans;

  bool leftToRight = true;  
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();          
    vector<int> currLevel(levelSize);  

    for (int i = 0; i < levelSize; i++) {
      TreeNode* front = q.front();  
      q.pop();
      int idx = leftToRight ? i : (levelSize - 1 - i);
      currLevel[idx] = front->val;
      if (front->left) q.push(front->left);
      if (front->right) q.push(front->right);
    }

    leftToRight = !leftToRight;
    ans.push_back(currLevel);
  }

  return ans;
}

int main() {
  //        1
  //       / \
  //      2   3
  //     / \ / \
  //    4  5 6  7
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Perform zigzag traversal
  vector<vector<int>> result = zigZagTraversal(root);

  // Print the result
  for (const auto& level : result) {
    for (int val : level) {
      cout << val << " ";
    }
    cout << endl;
  }

  // Expected Output:
  // 1
  // 3 2
  // 4 5 6 7

  return 0;
}
