#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

vector<vector<int>> treeTraversal3(TreeNode* root){
  vector<vector<int>> ans;
  if(root == nullptr) return ans;
  vector<int> in, pre, post;
  stack<pair<TreeNode*, int>> st;
  st.push({root, 1});
  while (!st.empty())
  {
    pair<TreeNode*, int> curr = st.top();
    st.pop();
    if(curr.first == nullptr) continue;

    if(curr.second == 1){
      pre.push_back(curr.first->val);
      st.push({curr.first, 2});
      if(curr.first->left) st.push({curr.first->left, 1});
    }else if(curr.second == 2){
      in.push_back(curr.first->val);
      st.push({curr.first, 3});
      if(curr.first->right) st.push({curr.first->right, 1});
    }else{
      post.push_back(curr.first->val);
    }
  }
  ans.push_back(pre);
  ans.push_back(in);
  ans.push_back(post);
  return ans;
}


int main(){
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

  vector<vector<int>> result = treeTraversal3(root);
  cout << "Preorder: ";
  for (int num : result[0]) cout << num << " ";
  cout << "\nInorder: ";
  for (int num : result[1]) cout << num << " ";
  cout << "\nPostorder: ";
  for (int num : result[2]) cout << num << " ";

  return 0;
}