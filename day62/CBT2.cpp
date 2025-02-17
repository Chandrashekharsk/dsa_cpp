#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> inMap, int inStart, int inEnd, int& postIndex){
  if(inStart>inEnd) return nullptr;

  int inRootIdx = inMap[postorder[postIndex]];
  TreeNode* root = new TreeNode(postorder[postIndex]);
  postIndex = postIndex-1;

  TreeNode* rightTree = buildTree(inorder, postorder, inMap, inRootIdx+1, inEnd, postIndex);
  TreeNode* leftTree = buildTree(inorder, postorder, inMap, inStart, inRootIdx-1, postIndex);
  root->left = leftTree;
  root->right = rightTree;
  return root;
}

TreeNode* counstructUniqueTree(vector<int>& inorder, vector<int>& postorder){
  unordered_map<int, int> inMap;
  for(int i=0; i<inorder.size(); ++i) inMap[inorder[i]] = i;
  int postIndex = postorder.size()-1;
  return buildTree(inorder, postorder, inMap, 0, inorder.size()-1, postIndex);
}

// Inorder traversal for verification
void printInorder(TreeNode* root) {
  if (!root) return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}
void printpostorder(TreeNode* root) {
  if (!root) return;
  printpostorder(root->left);
  printpostorder(root->right);
  cout << root->val << " ";
}



int main(){
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  TreeNode* root = counstructUniqueTree(inorder, postorder);

  cout << "Inorder traversal of constructed tree: ";
  printInorder(root);
  cout << endl;
  cout << "postorder traversal of constructed tree: ";
  printpostorder(root);
  cout << endl;

  return 0;
}