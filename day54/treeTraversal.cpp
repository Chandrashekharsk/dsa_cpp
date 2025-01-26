#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int n): data(n), left(nullptr), right(nullptr){};
};

void inorderTraversal(Node* root){
  if(root == nullptr) return;
  inorderTraversal(root->left);
  cout<<root->data<<" ";
  inorderTraversal(root->right);
}
void prevorderTraversal(Node* root){
  if(root == nullptr) return;
  cout<<root->data<<" ";
  inorderTraversal(root->left);
  inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
  if(root == nullptr) return;
  inorderTraversal(root->left);
  inorderTraversal(root->right);
  cout<<root->data<<" ";
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root-> right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  inorderTraversal(root);
  cout<<endl;
  prevorderTraversal(root);
  cout<<endl;
  postorderTraversal(root);

  return 0;
}