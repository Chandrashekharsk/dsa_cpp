// 102. Binary Tree Level Order Traversal
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(NULL), right(NULL) {};
};

vector<vector<int>> bfs_traversal2(TreeNode* root){
  vector<vector<int>> ans;
  if(root == nullptr) return ans;
  queue<TreeNode*> q;
  q.push(root);
  
  while (!q.empty()){
    int currLevelSize = q.size();
    vector<int> level;

    // traverse whole level
    for(int i=0; i<currLevelSize; i++){
      TreeNode* curr = q.front();
      level.push_back(curr->val);
      q.pop();
      if(curr->left != nullptr) q.push(curr->left);
      if(curr->right != nullptr) q.push(curr->right);
    };

    ans.push_back(level);
  }
  return ans;
}

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int currLevelSize = q.size();

            vector<int> level;
            for(int i=0; i<currLevelSize; i++){
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                q.pop();

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

int main(){
  //       1
  //   2       3
  // 4   5    6  7
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // bfs_traversal(root);
  cout<<endl;
  for(auto i: bfs_traversal2(root)){
    for(auto j: i ){
      cout<< j<< " ";
    }
    cout<< "\n";
  }

  return 0;
}