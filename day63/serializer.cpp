#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int n) : val(n), left(nullptr), right(nullptr) {};
};

string serializer(TreeNode* root) {
  if (!root) return "";
  string s = "";
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr == nullptr) {
      s.append("#,");
    } else {
      s.append(to_string(curr->val) + ',');
      q.push(curr->left);
      q.push(curr->right);
    }
  }
  return s;
}

TreeNode* deserializer(string dataString) {
  if (dataString.size() == 0) return nullptr;
  string str;
  stringstream s(dataString);
  getline(s, str, ',');

  TreeNode* root = new TreeNode(stoi(str));
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();

    // Deserialize left child
    if (getline(s, str, ',')) {
      if (str == "#") {
        curr->left = nullptr;
      } else {
        TreeNode* left = new TreeNode(stoi(str));
        curr->left = left;
        q.push(left);
      }
    };

    // Deserialize right child
    if (getline(s, str, ',')) {
      if (str == "#") {
        curr->right = nullptr;
      } else {
        TreeNode* right = new TreeNode(stoi(str));
        curr->right = right;
        q.push(right);
      }
    }
  }
  return root;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  string serialized = serializer(root);
  cout << "Serialized: " << serialized << endl;

  TreeNode* deserializedRoot = deserializer(serialized);
  string deserializedSerialized = serializer(deserializedRoot);
  cout << "Deserialized and Serialized again: " << deserializedSerialized << endl;

  return 0;
}
