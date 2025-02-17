#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void helper(TreeNode* root, int val, vector<int>& path, vector<int>& ans){
  if(!root) return;
  ans.push_back(root->val);
  
  if(root->val == val){
    for(auto i: ans) path.push_back(i);
    return;
  };
  
  if(root->left) helper(root->left, val,path, ans);
  if(root->right) helper(root->right, val,path, ans);
  ans.pop_back();
};

vector<int> rootToNodePath(TreeNode* root, int val){
  vector<int> ans;
  vector<int> path;
  helper(root, val, path, ans);
  return path;
}


bool getPath2(TreeNode* root, int val, vector<int>& ans){
  if(!root) return false;
  ans.push_back(root->val);
  if(root->val == val) return true;

  if(getPath2(root->left, val, ans) || getPath2(root->right, val, ans)) return true;

  ans.pop_back();
  return false;
}

vector<int> rootToNodePath3(TreeNode* root, int val){
  vector<int> ans;
  if(!root) return ans;
  getPath2(root, val, ans);
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

  // auto res = rootToNodePath(root, 6);
  // for(auto& i: res) cout<< i<<" ";

  auto res3 = rootToNodePath3(root, 6);
  for(auto& i: res3) cout<< i<<" ";
  


  return 0;
}