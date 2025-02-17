#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};


void leftTraversal(TreeNode* root, vector<int>& leftVec){
  if( root == nullptr) return;
  leftVec.push_back(root->val);
  leftTraversal(root->left, leftVec);
}

void rightTraversal(TreeNode* root, vector<int>& rightVec){
  if( root == nullptr) return;
  rightVec.push_back(root->val);
  rightTraversal(root->right, rightVec);
}


vector<int> topView(TreeNode* root){
  vector<int> ans;
  if(!root) return ans;
  
  vector<int> res1;
  leftTraversal(root->left, res1);
  reverse(res1.begin(), res1.end());
  vector<int> res2;
  rightTraversal(root->right, res2);
  
  for(auto i: res1) ans.push_back(i);
  ans.push_back(root->val);
  for(auto i: res2) ans.push_back(i);
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