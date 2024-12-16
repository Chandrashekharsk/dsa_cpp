#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int n): val(n), left(nullptr), right(nullptr){};
};

int depthOfBST(Node* root){
  if(root == nullptr) return 0;
  int lh = root->left->val;
  int rh = root->right->val;
  return 1+ max(lh, rh);
}

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(6);
  root->right->left->left = new Node(5);
  cout<<depthOfBST(root);


  return 0;
}