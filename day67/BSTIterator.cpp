// 173. Binary Search Tree Iterator
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

class BSTIterator {
 private:
  stack<TreeNode*> myStack;

  void pushAll(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
      myStack.push(curr);
      curr = curr->left;
    };
  }

 public:
  BSTIterator(TreeNode* root) { pushAll(root); }

  bool hasNext() { 
    return !myStack.empty(); 
  };

  int next() {
    TreeNode* curr = myStack.top();
    myStack.pop();
    pushAll(curr->right);
    return curr->val;
  }
};

int main() {
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator it(root);
  while (it.hasNext()) {
    cout << it.next() << " ";
  }
  // Expected output: 3 7 9 15 20

  return 0;
}