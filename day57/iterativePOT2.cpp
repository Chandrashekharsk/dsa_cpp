#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TreeNode definition
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Postorder Traversal (LEFT -> RIGHT -> ROOT)
vector<int> iterativePostorderTraversal(TreeNode* root) {
  vector<int> ans;
  if (!root) return ans;

  stack<TreeNode*> st;

  TreeNode* curr = root;
  while(curr != nullptr || !st.empty()){
    if(curr != nullptr){
      st.push(curr);
      curr = curr->left;
    }else{
      TreeNode* temp = st.top()->right;
      if(temp == nullptr){
        temp = st.top();
        st.pop();
        ans.push_back(temp-> val);
        while(!st.empty() && temp == st.top()->right){
          temp = st.top();
          st.pop();
          ans.push_back(temp->val);
        }
      }else{
        curr = temp;
      }
    }
  }

  return ans;
}

// Function to build a sample tree
TreeNode* buildSampleTree() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  return root;
}

int main() {
  TreeNode* root = buildSampleTree();

  vector<int> postorder = iterativePostorderTraversal(root);
  for (int val : postorder) cout << val << " ";
  cout << endl;                                

  return 0;
}
