#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

int widthOfBT(TreeNode* root) {
  if (!root) return 0;
  int ans = 0;
  queue<pair<TreeNode*, int>> q;  // store node and index
  q.push({root, 0});

  while (!q.empty()) {
    int size = q.size();
    int mini = q.front().second;   // take minimum of the curr level
    int first, last;
    for (int i = 0; i < size; ++i) {
      TreeNode* currNode = q.front().first;
      int currVal = q.front().second - mini;   // access second value from pair present in front of queue
      q.pop();

      if (i == 0) first = currVal;
      if (i == size - 1) last = currVal;
      if (currNode->left) q.push({currNode->left, currVal * 2 + 1});
      if (currNode->right) q.push({currNode->right, currVal * 2 + 2});
    }
    ans = max(ans, last - first + 1);
  }
  return ans;
}

int main() { 

  TreeNode* root = new TreeNode(5);
  cout<< widthOfBT(root);
  return 0; 
}