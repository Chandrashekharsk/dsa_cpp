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

TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, unordered_map<int,int> inMap, int inStart, int inEnd, int& preIndex){
  if(inStart>inEnd) return nullptr;

  int inRootIdx = inMap[preorder[preIndex]];
  TreeNode* root = new TreeNode(preorder[preIndex++]);
  // preIndex = preIndex+1;

  TreeNode* leftTree = buildTree(inorder, preorder, inMap, inStart, inRootIdx-1, preIndex);
  TreeNode* rightTree = buildTree(inorder, preorder, inMap, inRootIdx+1, inEnd, preIndex);
  root->left = leftTree;
  root->right = rightTree;
  return root;
}

TreeNode* counstructUniqueTree(vector<int>& inorder, vector<int>& preorder){
  unordered_map<int, int> inMap;
  for(int i=0; i<inorder.size(); ++i) inMap[inorder[i]] = i;
  int preIndex = 0;
  return buildTree(inorder, preorder, inMap, 0, inorder.size()-1, preIndex);
}


TreeNode* buildTree2(vector<int>& inorder, vector<int>& preorder, unordered_map<int,int> inMap, int inStart, int inEnd, int preStart, int preEnd){
  if(inStart>inEnd) return nullptr;

  int inRootIdx = inMap[preorder[preStart]];
  TreeNode* root = new TreeNode(preorder[preStart]);
  

  TreeNode* leftTree = buildTree2(inorder, preorder, inMap, inStart, inRootIdx-1,
    preStart+1, preStart+(inRootIdx-inStart));
  TreeNode* rightTree = buildTree2(inorder, preorder, inMap, inRootIdx+1, inEnd, preStart+(inRootIdx-inStart)+1, preEnd);
  root->left = leftTree;
  root->right = rightTree;
  return root;
}

TreeNode* counstructUniqueTree2(vector<int>& inorder, vector<int>& preorder){
  unordered_map<int, int> inMap;
  for(int i=0; i<inorder.size(); ++i) inMap[inorder[i]] = i;
  return buildTree2(inorder, preorder, inMap, 0, inorder.size()-1, 0, preorder.size()-1);
}

// Inorder traversal for verification
void printInorder(TreeNode* root) {
  if (!root) return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}
void printPreorder(TreeNode* root) {
  if (!root) return;
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}



int main(){
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> preorder = {3, 9, 20, 15, 7};

  TreeNode* root = counstructUniqueTree2(inorder, preorder);

  cout << "Inorder traversal of constructed tree: ";
  printInorder(root);
  cout << endl;
  cout << "Preorder traversal of constructed tree: ";
  printPreorder(root);
  cout << endl;

  return 0;
}