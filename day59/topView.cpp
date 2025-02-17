#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};


vector<int> topView(TreeNode* root){
  vector<int> ans;
  if(!root) return ans;
  
  map<int, TreeNode*> m;
  queue<pair<TreeNode*, int>> q;

  q.push({root,0});

  while(!q.empty()){
    auto curr = q.front();
    q.pop();
    if(!m[curr.second]){
      m[curr.second] = curr.first;
    }
    if(curr.first->left) q.push({curr.first->left, curr.second-1});
    if(curr.first->right) q.push({curr.first->right, curr.second+1});
  }

  for(auto& i: m){
    ans.push_back(i.second->val);
  };
  return ans;
}

int main(){
  // Sample Binary Tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->right->left = new TreeNode(8);

  /*
            1
           / \
          2   3
         / \  /\
        4   56  7
                /
               8
  */

  auto result = topView(root);

  cout << "top view Traversal:\n";
  for (auto& i : result) {
    cout<< i<<" ";
  }
  cout << endl;

  return 0;
}