#include <iostream>
using namespace std;

// Define a generic ListNode structure
template <typename T>
struct ListNode {
  T data;
  ListNode* next;
  ListNode(T x) : data(x), next(nullptr) {}
};

// Define a generic Stack class
template <typename T>
class Stack {
 private:
  ListNode<T>* head;  // Head of the linked list
  int cnt;            // Count of elements

 public:
  static string type;

  Stack() {
    head = nullptr;
    cnt = 0;
  }

  bool isEmpty() { return head == nullptr; }

  void push(T arg) {
    ListNode<T>* newNode = new ListNode<T>(arg);
    newNode->next = head;
    head = newNode;
    ++cnt;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack Underflow! Cannot pop.\n";
      return;
    }
    ListNode<T>* temp = head;
    head = head->next;
    delete temp;
    --cnt;
  }

  T top() {
    if (isEmpty()) {
      cout << "Stack is empty! No top element.\n";
      return T();  // Default return value for generic type
    }
    return head->data;
  }

  int size() { return cnt; }

  void print() {
    if (isEmpty()) {
      cout << "Stack is empty!\n";
      return;
    }
    ListNode<T>* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

// Define type names for different types
template <>
string Stack<int>::type = "Integer Stack";
template <>
string Stack<float>::type = "Float Stack";
template <>
string Stack<string>::type = "String Stack";

int main() {
  // Integer Stack
  Stack<int> s1;
  cout << "Type: " << Stack<int>::type << endl;
  s1.push(10);
  s1.push(20);
  s1.print();                           // 20 10
  cout << "Top: " << s1.top() << endl;  // 20
  s1.pop();
  s1.print();  // 10

  // Float Stack
  Stack<float> s2;
  cout << "Type: " << Stack<float>::type << endl;
  s2.push(1.1);
  s2.push(2.2);
  s2.print();  // 2.2 1.1

  // String Stack
  Stack<string> s3;
  cout << "Type: " << Stack<string>::type << endl;
  s3.push("Hello");
  s3.push("World");
  s3.print();  // World Hello

  return 0;
}
