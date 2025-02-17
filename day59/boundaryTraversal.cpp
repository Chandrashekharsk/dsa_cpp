#include <deque>
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

vector<vector<int>> boundaryTravesal(TreeNode* root) {
  vector<vector<int>> ans;
  queue<TreeNode*> my_queue;

  my_queue.push(root);
  deque<int> my_dqueue;

  while (!my_queue.empty()) {
    TreeNode* temp = my_queue.front();
    my_dqueue.push_back(temp->val);
    my_queue.pop();
    if (temp->left) my_queue.push(temp->left);
    if (temp!= root && temp->right) my_queue.push(temp->right);
  }
  ans.push_back(vector<int>(my_dqueue.begin(), my_dqueue.end()));
  my_dqueue.clear();

  my_queue.push(root->right);
  while (!my_queue.empty()) {
    TreeNode* temp = my_queue.front();
    my_dqueue.push_front(temp->val);
    my_queue.pop();
    if (temp->right) my_queue.push(temp->right);
    if (temp->left) my_queue.push(temp->left);
  }
  ans.push_back(vector<int>(my_dqueue.begin(), my_dqueue.end()));
  return ans;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);

  root->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(4);
  root->left->left->right->left = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);

  root->right = new TreeNode(7);
  root->right->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->right->left->left = new TreeNode(10);
  root->right->right->left->right = new TreeNode(11);
  for (auto& it : boundaryTravesal(root)) {
    for (auto& i : it) cout << i << " ";
  };

  return 0;
}