// iterative TeeNode traversal
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

// ROOT LEFT RIGHT - (ROOT RIGHT LEFT)
vector<int> preOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  stack<TreeNode*> st;
  st.push(root);

  while(!st.empty()){
    TreeNode* curr = st.top();
    ans.push_back(curr->val);
    st.pop();
    if(curr->right != nullptr) st.push(curr->right);
    if(curr->left != nullptr) st.push(curr->left);
  }
  return ans;
}

// LEFT RIGHT ROOT - (LEFT ROOT RIGHT)
vector<int> inOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  stack<TreeNode*> st;
  TreeNode* curr = root;

  while(curr != nullptr || !st.empty()){
    while(curr != nullptr){
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    ans.push_back(curr->val);
    curr = curr->right;
  }

  return ans;
}

// LEFT RIGHT ROOT - (ROOT LEFT RIGHT | ROOT)
// using 2 stack
vector<int> postOrderTraversal(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  stack<TreeNode*> st1, st2;
  st1.push(root);

  while(!st1.empty()){
    TreeNode* curr = st1.top();
    st1.pop();
    st2.push(curr);
    if(curr->left != nullptr) st1.push(curr->left);
    if(curr->right != nullptr) st1.push(curr->right);
  }

  while(!st2.empty()){
    TreeNode* curr = st2.top();
    st2.pop();
    ans.push_back(curr->val);
  }

  return ans;
}

// LEFT RIGHT ROOT - (ROOT LEFT RIGHT | ROOT)
// using 1 stack
vector<int> postOrderTraversal2(TreeNode* root){
  vector<int> ans;
  if(root == nullptr) return ans;
  stack<TreeNode*> st;

  TreeNode* curr = root;
  TreeNode* lastVisited = nullptr;

  while(curr != nullptr || !st.empty()){
    if(curr != nullptr){
      st.push(curr);
      curr = curr->left;
    }else{
      TreeNode* top = st.top();
      if(top->right != nullptr && top->right != lastVisited){
        curr = top->right;
      }else{
        ans.push_back(top->val);
        st.pop();
        lastVisited = top;
      }
    }
  }

  return ans;
}


int main(){
    //       1
    //   2      3
    // 4   5  6   7
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // for(auto i: preOrderTraversal(root)) cout<< i<<" ";
  // cout<<"\n";
  // for(auto i: inOrderTraversal(root)) cout<< i<<" ";
  // cout<<"\n";
  // for(auto i: postOrderTraversal(root)) cout<< i<<" ";
  // cout<<"\n";
  for(auto i: postOrderTraversal2(root)) cout<< i<<" ";
  cout<<"\n";

  return 0;
}