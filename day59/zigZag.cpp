#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

vector<vector<int>> zigZagTreeTraversal(TreeNode* root){
  vector<vector<int>> ans;
  queue<TreeNode*> q;
  bool leftToRight = true;

  q.push(root);
  while(!q.empty()){
    int size = q.size();
    deque<int> currLevel;

    for (int i=0; i<size; ++i){
      TreeNode* temp = q.front();
      if(leftToRight) currLevel.push_back(temp->val);
      else currLevel.push_front(temp->val);
      
      q.pop();
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    };

    leftToRight = !leftToRight;
    ans.push_back(vector<int>(currLevel.begin(), currLevel.end()));
  }
  return ans;
}

int main(){

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->right->left = new TreeNode(8);
  root->right->right->right = new TreeNode(9);
  auto res = zigZagTreeTraversal(root);
  for(auto& i: res){
    for(auto& it: i){
      cout<< it<<" ";
    }
    cout<<endl;
  }


  return 0;
}