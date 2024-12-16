#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;          // Value of the node
  TreeNode* left;   // Pointer to the left child
  TreeNode* right;  // Pointer to the right child
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// using preorder traversal
bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr || q == nullptr) return p == q;
  return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  // **Sample Input 1: Trees are the Same**
  TreeNode* p1 = new TreeNode(1);
  p1->left = new TreeNode(2);
  p1->right = new TreeNode(3);

  TreeNode* q1 = new TreeNode(1);
  q1->left = new TreeNode(2);
  q1->right = new TreeNode(3);

  cout << "Sample Input 1: Trees are the Same" << endl;
  cout << boolalpha << isSameTree(p1, q1) << endl;  // Expected Output: true

  // **Sample Input 2: Trees are Different**
  TreeNode* p2 = new TreeNode(1);
  p2->left = new TreeNode(2);

  TreeNode* q2 = new TreeNode(1);
  q2->right = new TreeNode(2);

  cout << "Sample Input 2: Trees are Different" << endl;
  cout << boolalpha << isSameTree(p2, q2) << endl;  // Expected Output: false

  // **Sample Input 3: Trees with Different Structures**
  TreeNode* p3 = new TreeNode(1);
  p3->left = new TreeNode(2);
  p3->right = new TreeNode(1);

  TreeNode* q3 = new TreeNode(1);
  q3->left = new TreeNode(1);
  q3->right = new TreeNode(2);

  cout << "Sample Input 3: Trees with Different Structures" << endl;
  cout << boolalpha << isSameTree(p3, q3) << endl;  // Expected Output: false

  // **Sample Input 4: Both Trees are Empty**
  TreeNode* p4 = nullptr;
  TreeNode* q4 = nullptr;

  cout << "Sample Input 4: Both Trees are Empty" << endl;
  cout << boolalpha << isSameTree(p4, q4) << endl;  // Expected Output: true

  return 0;
}
