#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode* next;
  ListNode(int x) : data(x), next(nullptr) {}
};

class Stack {
 private:
  ListNode* head;
  int cnt;

 public:
  static string type;
  Stack() {
    head = nullptr;
    cnt = 0;
  }

  bool isEmpty() { return head == nullptr; }

  void push(int arg) {
    ListNode* newNode = new ListNode(arg);
    newNode->next = head;
    head = newNode;
    ++cnt;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack Underflow! Cannot pop.\n";
      return;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    --cnt;
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack is empty! No top element.\n";
      return -1;
    }
    return head->data;
  }

  int size() { return cnt; }

  void print() {
    if (isEmpty()) {
      cout << "Stack is empty!\n";
      return;
    }
    ListNode* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

string Stack:: type = "Stack";

int main() {

  cout<< Stack::type << endl;  

  Stack s;
  s.push(2);
  s.push(3);

  cout << s.size() << endl;  // ✅ Should print 2
  cout<< s.top() << endl;    // ✅ Should print 3

  s.pop();
  cout << s.size() << endl;  // ✅ Should print 1

  s.pop();
  s.pop();  

  cout << (s.isEmpty() ? "Yes" : "No") << endl; 

  return 0;
}
