#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

// iterative approach
vector<int> leftView(TreeNode* root){
  if(!root) return {};
  map<int, int> m;
  queue<pair<TreeNode*, int>> q;
  q.push({root, 0});

  while(!q.empty()){
    auto curr = q.front();
    q.pop();
    int y = curr.second;
    if(!m[y])m[y] = curr.first->val;
    if(curr.first->left) q.push({curr.first->left, y+1});
    if(curr.first->right) q.push({curr.first->right, y+1});
  }

  vector<int> ans;

  for (auto& i: m){
    ans.push_back(i.second);
  }
  return ans;
}

void recursiveApp(TreeNode* root, int level, vector<int>& ans){
  if(!root) return;
  if(level == ans.size()) ans.push_back(root->val);

  if(root->left) recursiveApp(root->left, level+1, ans);
  if(root->right) recursiveApp(root->right, level+1, ans);
}
// recursive approach
vector<int> leftView2(TreeNode* root){
  if(!root) return {};
  vector<int> ans;
  recursiveApp(root, 0, ans);
  return ans;
}

int main(){

  TreeNode* root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);

  root->right = new TreeNode(3);
  root->right->right = new TreeNode(7);

  auto res = leftView2(root);
  for(auto& i: res) cout<< i<<" ";
  // auto res = leftView(root);
  // for(auto& i: res) cout<< i<<" ";


  return 0;
}