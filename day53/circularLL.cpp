#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class CircularLL {
  Node* head;
  Node* tail;

 public:
  CircularLL() {
    head = nullptr;
    tail = nullptr;
  }

  void insertAtHead(int n) {
    Node* newNode = new Node(n);
    if (head == nullptr) {
      newNode->next = newNode;
      head = tail = newNode;
    } else {
      newNode->next = head;
      tail->next = newNode;
      head = newNode;
    }
  }

  void insertAtTail(int n) {
    Node* newNode = new Node(n);
    if (head == nullptr) {
      newNode->next = newNode;
      head = tail = newNode;
    } else {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void printList() {
    if (head == nullptr) {
      cout << "List is empty" << endl;
      return;
    }

    Node* temp = head;
    do {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;  // To indicate circularity
  }

  void deleteAtHead() {
    if (head == nullptr) return;

    Node* temp = head;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      head = head->next;
      tail->next = head;
    }

    temp->next = nullptr;  // Disconnect the node before deletion
    delete temp;
  }

  void deleteAtTail() {
    if (head == nullptr) return;

    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node* temp = head;

      while (temp->next != tail) {
        temp = temp->next;
      }

      Node* oldTail = tail;
      tail = temp;
      tail->next = head;

      oldTail->next = nullptr;  
      delete oldTail;
    }
  }
};

int main() {
  CircularLL ll;

  ll.insertAtHead(4);
  // ll.insertAtHead(3);
  // ll.insertAtTail(5);

  // ll.printList();

  // ll.deleteAtHead();
  // ll.printList();

  ll.deleteAtTail();
  ll.printList();

  return 0;
}
