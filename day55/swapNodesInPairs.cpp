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
  ListNode* reverseKGroup(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0, k=2;
    // skip k nodes
    while(cnt<k){ 
      if(!temp) return head;
      temp = temp->next;
      ++cnt;
    }

    // recursively call for rest of ll  (move to the last group)
    ListNode* reversedListHead = reverseKGroup(temp);

    // reverse current group
    temp = head; cnt = 0;
    while (cnt<k){
      ListNode* next = temp->next;
      temp->next = reversedListHead;
      reversedListHead = temp;
      temp = next;
      ++cnt;
    }
    return reversedListHead;
  }

  ListNode* swapNodesInPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* prev = nullptr;
    
    while(first && second){
      first->next = second->next;
      second->next = first;
      if(prev) prev->next = second;
      else head = second;

      // update pointers
      prev = first;
      first = first->next;
      if(first) second = first->next;
      else second = nullptr;
    }
    return head;
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

  ListNode* head = createLinkedList(values);
  cout << "Original List: ";
  printLinkedList(head);

  head = solution.swapNodesInPairs(head);
  cout << "Reversed List: ";
  printLinkedList(head);

  return 0;
}
