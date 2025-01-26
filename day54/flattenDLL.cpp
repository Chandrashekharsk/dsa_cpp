// 430. Flatten a Multilevel Doubly Linked List
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
  Node* child;

  Node(int n) : data(n), prev(nullptr), next(nullptr), child(nullptr) {}
};

// Function to print the doubly linked list
void printList(Node* head) {
  Node* temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Function to flatten a multilevel doubly linked list
Node* flattenList(Node* head) {
  Node* curr = head;

  while (curr) {
    if (curr->child) {
      // Store the next node
      Node* temp = curr->next;

      // Flatten the child list and attach it
      Node* childList = flattenList(curr->child);
      curr->next = childList;
      childList->prev = curr;

      // Clear the child pointer
      curr->child = nullptr;

      // Find the tail of the flattened child list
      while (curr->next) {
        curr = curr->next;
      }

      // Reconnect the tail to the stored next node
      if (temp) {
        curr->next = temp;
        temp->prev = curr;
      }
    }

    // Move to the next node
    curr = curr->next;
  }
  return head;
}

// Function to create a sample multilevel doubly linked list
Node* createSampleList() {
  Node* head = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  Node* node8 = new Node(8);
  Node* node9 = new Node(9);
  Node* node10 = new Node(10);

  // Link the main list
  head->next = node2;
  node2->prev = head;

  node2->next = node3;
  node3->prev = node2;

  node3->next = node4;
  node4->prev = node3;

  node4->next = node5;
  node5->prev = node4;

  // Add child nodes
  node3->child = node6;
  node6->next = node7;
  node7->prev = node6;
  node7->next = node8;
  node8->prev = node7;

  node7->child = node9;
  node9->next = node10;
  node10->prev = node9;

  return head;
}

int main() {
  // Create the sample list
  Node* head = createSampleList();

  cout << "Original List: ";
  printList(head);

  // Flatten the list
  Node* flattenedList = flattenList(head);

  // Print the flattened list
  cout << "Flattened List: ";
  printList(flattenedList);

  return 0;
}
