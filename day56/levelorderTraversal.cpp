#include <deque>
#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode* left;
  ListNode* right;
  ListNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(ListNode* root) {
  if (root == nullptr) return;

  deque<ListNode*> dq;
  dq.push_back(root);

  while (!dq.empty()) {
    int currSize = dq.size();

    for (int i = 0; i < currSize; ++i) {
      ListNode* currNode = dq.front();
      dq.pop_front();  // Efficient pop in deque

      cout << currNode->data << " ";

      if (currNode->left) dq.push_back(currNode->left);
      if (currNode->right) dq.push_back(currNode->right);
    }
    cout << endl;
  }
}

int main() {
  ListNode* root = new ListNode(1);
  root->left = new ListNode(2);
  root->right = new ListNode(3);
  root->left->left = new ListNode(4);
  root->left->right = new ListNode(5);
  root->right->left = new ListNode(6);
  root->right->right = new ListNode(7);

  cout << "Level Order Traversal:\n";
  levelOrderTraversal(root);

  return 0;
}
