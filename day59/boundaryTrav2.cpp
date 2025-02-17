#include<iostream>
#include<vector>
#include<deque>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

bool isLeaf(TreeNode* root){
  if(root == nullptr) return false;
  return !root->left && !root->right;
}

void addLeftBoundary(TreeNode* root, vector<int>& leftBoundary){
  TreeNode* temp = root->left;
  while(temp){
    if(!isLeaf(temp)) leftBoundary.push_back(temp->val);
    if(temp->left) temp = temp->left;
    else temp = temp->right;
  }
}

void addLeafNodes(TreeNode* root, vector<int>& leafNodes){
  if(root==nullptr) return;

  if(!root->left && !root->right){
    leafNodes.push_back(root->val);
    return;
  };
  addLeafNodes(root->left, leafNodes);
  addLeafNodes(root->right, leafNodes);
}

void addRightBoundary(TreeNode* root, deque<int>& rightBoundary){
  TreeNode* temp = root->right;
  while(temp){
    if(!isLeaf(temp)) rightBoundary.push_front(temp->val);
    if(temp->right) temp = temp->right;
    else temp = temp->left;
  }
}




vector<int> boundaryTraversal(TreeNode* root){
  if(!root) return {};
  vector<int> ans;

  // manually pushing root's value
  if (!isLeaf(root)) ans.push_back(root->val);

  vector<int> leftBoundary;
  addLeftBoundary(root, leftBoundary);
  ans.insert(ans.end(), leftBoundary.begin(), leftBoundary.end());

  vector<int> leafBoundary;
  addLeafNodes(root, leafBoundary);
  ans.insert(ans.end(), leafBoundary.begin(), leafBoundary.end());

  deque<int> righBoundary;
  addRightBoundary(root, righBoundary);
  ans.insert(ans.end(), righBoundary.begin(), righBoundary.end());
  return ans;
} 

int main(){
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(30);
    root->left->left->left->left = new TreeNode(60);
    root->left->left->left->left->left = new TreeNode(70);
    root->left->left->left->left->right = new TreeNode(80);

    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vector<int> result = boundaryTraversal(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
  


  return 0;
}