#include <iostream>
#include <queue>
#include <unordered_set>
#include<unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

vector<int> findNodes(TreeNode* tar, int kDis,unordered_map<TreeNode*, TreeNode*> m) {
  vector<int> ans;
  unordered_set<TreeNode*> vis;
  queue<TreeNode*> q;
  q.push(tar);
  vis.insert(tar);
  int currDis = 0;

  while (!q.empty()) {
    if (currDis == kDis) break;
    int level = q.size();
    for (int i = 0; i < level; ++i) {
      TreeNode* curr = q.front();
      q.pop();
      if (curr->left && !vis.count(curr->left)) {
        q.push(curr->left);
        vis.insert(curr->left);
      };
      if (curr->right && !vis.count(curr->right)) {
        q.push(curr->right);
        vis.insert(curr->right);
      };
      if (m[curr] && !vis.count(m[curr])) {
        q.push(m[curr]);
        vis.insert(m[curr]);
      };
    }
    ++currDis;
  }
  while (!q.empty()) {
    TreeNode* temp = q.front();
    ans.push_back(temp->val);
    q.pop();
  }
  return ans;
}

vector<int> nodesAtKDistance(TreeNode* root, TreeNode* tar, int kDis) {
  if (!root || !tar || !kDis) return {};
  unordered_map<TreeNode*, TreeNode*> m;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr->left) {
      m[curr->left] = root;
      q.push(curr->left);
    };
    if (curr->right) {
      m[curr->right] = root;
      q.push(curr->right);
    };
  };

  return findNodes(tar, kDis, m);
};

int main() {
  TreeNode* root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  auto res = nodesAtKDistance(root, root->left, 2);
  for (auto& i : res) cout << i << " ";
  cout << endl;


  // unordered_multimap<int, string> ummp;
  // ummp.insert({3, "Alice"});  // O(1)
  // ummp.insert({3, "Charlie"});  // Duplicate key
  // ummp.insert({1, "Bob"});
  // for (auto it = ummp.begin(); it!= ummp.end(); ++it){
  //   cout<< it->first<<"->"<<it->second<<endl;
  // }

  return 0;
}