#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    
  }

 private:
  void reverse(ListNode* head, int k){
    

  };

  void reverseGroup(ListNode* start, ListNode* end) {
    ListNode* prev = nullptr;
    ListNode* curr = start;
    ListNode* stop = end->next;

    while (curr != stop) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
  }
};

// Helper function to create a linked list
ListNode* createLinkedList(const vector<int>& values) {
  ListNode* dummy = new ListNode();
  ListNode* current = dummy;
  for (int val : values) {
    current->next = new ListNode(val);
    current = current->next;
  }
  return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// Main function to test the solution
int main() {
  Solution solution;
  vector<int> values = {1, 2, 3, 4, 5};
  int k = 2;

  ListNode* head = createLinkedList(values);
  cout << "Original List: ";
  printLinkedList(head);

  head = solution.reverseKGroup(head, k);
  cout << "Reversed in Groups of " << k << ": ";
  printLinkedList(head);

  return 0;
}
