#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n): val(n), left(nullptr), right(nullptr){};
};

void treeTraversals(TreeNode* root, vector<int>& preOrder, vector<int>& inOrder, vector<int>& postOrder){
  if(root == nullptr) return;
  stack<pair<TreeNode*,int>> st;
  st.push({root, 1}); 

  while( !st.empty()){
    auto [node, state] = st.top();
    st.pop();
    
    if(state == 1){
      preOrder.push_back(node->val);
      st.push({node, 2});
      if(node->left) st.push({node->left, 1});
    }
    if(state == 2){
      inOrder.push_back(node->val);
      st.push({node, 3});
      if(node->right) st.push({node->right, 1});
    }
    if(state == 3){
      postOrder.push_back(node->val);
    }
  }
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

  vector<int> preOrder;
  vector<int> inOrder;
  vector<int> postOrder;
  treeTraversals(root, preOrder, inOrder, postOrder);

   // Print the traversals
    cout << "Pre-order Traversal: ";
    for (int val : preOrder) cout << val << " ";
    cout << "\nIn-order Traversal: ";
    for (int val : inOrder) cout << val << " ";
    cout << "\nPost-order Traversal: ";
    for (int val : postOrder) cout << val << " ";
    cout << endl;
  
  return 0;
}