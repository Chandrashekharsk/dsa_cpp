#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

int findMinBornTime(TreeNode* root, TreeNode* tarNode, unordered_map<TreeNode*, TreeNode*>&  par_track) {
  queue<TreeNode*> q;
  unordered_set<TreeNode*> vis;
  q.push(tarNode);
  vis.insert(tarNode);
  int dist = 0;

  while (!q.empty()) {
    int level = q.size();
    for (int i = 0; i < level; ++i) {
      TreeNode* curr = q.front();
      q.pop();
      if (curr->left && !vis.count(curr->left)) {
        q.push(curr->left);
        vis.insert(curr->left);
      }
      if (curr->right && !vis.count(curr->right)) {
        q.push(curr->right);
        vis.insert(curr->right);
      }
      if (par_track.find(curr) != par_track.end() && !vis.count(par_track[curr])) {
        q.push(par_track[curr]);
        vis.insert(par_track[curr]);
      }
    };
    if(!q.empty()) ++dist;
    ;
  }
  return dist;
}

int minTimeToBorn(TreeNode* root, TreeNode* tarNode) {
  unordered_map<TreeNode*, TreeNode*> um;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr->left) {
      um[curr->left] = curr;
      q.push(curr->left);
    };
    if (curr->right) {
      um[curr->right] = curr;
      q.push(curr->right);
    };
  };
  return findMinBornTime(root, tarNode, um);
}

int main() { 

//      3
//     / \
//    5   1
//   / \  / \
/   6   2 0  8
//     / \
//    7   4

  TreeNode* root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  auto res = minTimeToBorn(root, root->left);
  cout<<res;

  return 0; 
}