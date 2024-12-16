#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(NULL), right(NULL) {};
};

// ROOT LEFT RIGHT - (ROOT RIGHT LEFT)
vector<int> iterativePreOrderTraversel(TreeNode* root){
  vector<int> ans;
  if(root == NULL) return ans;
  stack<TreeNode*> st;

  st.push(root);
  while(!st.empty()){
    TreeNode* curr = st.top();
    st.pop();
    ans.push_back(curr->val);
    if( curr->right != NULL) st.push(curr->right);
    if( curr->left != NULL) st.push(curr->left);
  }
  return ans;
}

// LEFT RIGHT ROOT - (LEFT ROOT RIGHT)
vector<int> iterativeInOrderTraversel(TreeNode* root){
  vector<int> ans;
  if(root == NULL) return ans;
  stack<TreeNode*> st;
  TreeNode* curr = root;

  while (curr != NULL || !st.empty()) {
    while (curr != NULL) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    ans.push_back(curr->val);
    st.pop();
    
    curr = curr->right;
  }

  return ans;
}


// LEFT, RIGHT, ROOT - (ROOT, LEFT, RIGHT | ROOT)
vector<int> iterativePostOrderTraversel(TreeNode* root){
  vector<int> ans;
  if(root == NULL) return ans;
  stack<TreeNode*> st1, st2;

  st1.push(root);
  while(!st1.empty()){
    TreeNode* curr = st1.top();
    st1.pop();
    st2.push(curr);
    if( curr->left != NULL) st1.push(curr->left);
    if( curr->right != NULL) st1.push(curr->right);
  }
  
  while(!st2.empty()){
    TreeNode* curr = st2.top();
    st2.pop();
    ans.push_back(curr->val);
  }
  return ans;
}

int main(){
  //      1
  //   2    3
  // 4  5  6  7
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // for(auto i: iterativePreOrderTraversel(root)) cout<< i<<" ";
  for(auto i: iterativeInOrderTraversel(root)) cout<< i<<" ";
  // for(auto i: iterativePostOrderTraversel(root)) cout<< i<<" ";


  return 0;
}