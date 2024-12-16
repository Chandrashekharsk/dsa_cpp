#include <iostream>
#include <stdexcept>  // for out_of_range exception
using namespace std;

class List {
 private:
  struct Node {
    int val;
    Node *Next;
    Node(int n) : val(n), Next(nullptr) {};
  };
  Node *head;
  Node *tail;  // New tail pointer
  int size;

 public:
  List() : head(nullptr), tail(nullptr), size(0) {};

  // Pushes a value to the back of the list
  void push_back(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->Next = newNode;
      tail = newNode;
    }
    size++;
  }

  // Pushes a value to the front of the list
  void push_front(int val) {
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
    if (tail == nullptr) tail = newNode;
    size++;
  }

  // Removes the last element in the list
  void pop_back() {
    if (head == nullptr) return;
    
    if (head->Next == nullptr) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *curr = head;
      while (curr->Next != tail) {
        curr = curr->Next;
      }
      delete tail;
      tail = curr;
      tail->Next = nullptr;
    }
    size--;
  }

  // Removes the first element in the list
  void pop_front() {
    if (head == nullptr) return;
    Node *curr = head;
    head = head->Next;
    if (head == nullptr) tail = nullptr;  // Update tail if list becomes empty
    delete curr;
    size--;
  }

  // Inserts a value at a specified index in the list
  void insert_at(int index, int val) {
    if (index < 0 || index > size) return;

    if (index == 0) {
      push_front(val);
      return;
    }
    if (index == size) {
      push_back(val);
      return;
    }

    Node *newNode = new Node(val);
    Node *curr = head;
    for (int count = 0; count < index - 1; count++) {
      curr = curr->Next;
    }
    newNode->Next = curr->Next;
    curr->Next = newNode;
    size++;
  }

  // Removes an element at a specified index
  void remove_at(int index) {
    if (index < 0 || index >= size || head == nullptr) return;

    if (index == 0) {
      pop_front();
      return;
    }
    if (index == size - 1) {
      pop_back();
      return;
    }

    Node *curr = head;
    for (int count = 0; count < index - 1; count++) {
      curr = curr->Next;
    }
    Node *temp = curr->Next;
    curr->Next = curr->Next->Next;
    delete temp;
    size--;
  }

  // Returns the size of the list
  int size_of() const { return size; }

  // Checks if the list is empty
  bool is_empty() const { return head == nullptr; }

  // Returns the value of the front node
  int in_front() const {
    if (!head) throw out_of_range("List is empty");
    return head->val;
  }

  // Returns the value of the last node using the tail pointer
  int in_back() const {
    if (!tail) throw out_of_range("List is empty");
    return tail->val;
  }

  // Clears the entire list
  void clear() {
    while (head) {
      pop_front();
    }
  }

  // Displays the list
  void display() const {
    if (!head) return;
    Node *curr = head;
    while (curr != nullptr) {
      cout << curr->val << " ";
      curr = curr->Next;
    }
  }
};

int main() {
  List list;
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_front(2);
  list.push_front(1);

  cout << list.size_of() << " \n";
  list.display();
  cout << "\n";

  list.pop_back();
  list.pop_front();
  list.display();
  cout << "\n";
  cout << list.in_front() << "\n";
  cout << list.in_back() << "\n";

  list.insert_at(0, 1);
  list.display();
  cout << "\n";
  list.insert_at(3, 50);
  list.display();
  cout << "\n";
  list.remove_at(3);
  list.display();
  cout << "\n";

  cout << list.is_empty() << "\n";
  list.clear();
  cout << list.is_empty() << "\n";

  return 0;
}
