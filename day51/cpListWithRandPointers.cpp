// 138. Copy List with Random Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:

  Node* copyRandomList(Node* head) {
    Node* oldTemp = head;
    Node* newHead = new Node(-1);
    Node* newTemp = newHead;
    unordered_map<Node*, Node*> mpp;

    while (oldTemp != nullptr) {
      Node* newNode = new Node(oldTemp->val);
      mpp[oldTemp] = newNode;
      newTemp->next = newNode;

      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead->next;
    while (oldTemp != nullptr && newTemp != nullptr) {
      if (oldTemp->random) newTemp->random = mpp[oldTemp->random];
      newTemp = newTemp->next;
      oldTemp = oldTemp->next;
    }
    return newHead->next;
  }
};
// Helper function to print the list
void printList(Node* head) {
  while (head) {
    cout << "Node value: " << head->val;
    if (head->random) {
      cout << ", Random points to: " << head->random->val;
    } else {
      cout << ", Random points to: nullptr";
    }
    cout << endl;
    head = head->next;
  }
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int size) {
  if (size == 0) return nullptr;
  Node* head = new Node(arr[0]);
  Node* current = head;
  for (int i = 1; i < size; i++) {
    current->next = new Node(arr[i]);
    current = current->next;
  }
  return head;
}

// Helper function to set random pointers for the list
void setRandomPointers(Node* head) {
  if (!head) return;
  // Example random pointer assignments
  head->random = nullptr;
  head->next->random = head;
  head->next->next->random = head->next->next->next->next;
  head->next->next->next->random = head->next->next;
  head->next->next->next->next->random = head;
};

int main() {
  // Example input
  int arr[] = {7, 13, 11, 10, 1};
  Node* head = createList(arr, 5);

  // Set random pointers for the list
  setRandomPointers(head);

  Solution solution;
  Node* copiedList = solution.copyRandomList(head);

  cout << "Original List:" << endl;
  printList(head);

  cout << "\nCopied List:" << endl;
  printList(copiedList);

  return 0;
}
