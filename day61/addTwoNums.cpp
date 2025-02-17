// 2. Add Two Numbers
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int n) : val(n), next(nullptr) {}
};

ListNode* addTwoNums(ListNode* l1, ListNode* l2) {
  ListNode* dummyList = new ListNode(-1);
  ListNode* curr = dummyList;
  int carry = 0;

  while (l1 || l2 || carry) {
    int sum = carry;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
    carry = sum / 10;
  }
  return dummyList->next;
}


// Function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
  if (nums.empty()) return nullptr;
  ListNode* head = new ListNode(nums[0]);
  ListNode* temp = head;
  for (size_t i = 1; i < nums.size(); i++) {
    temp->next = new ListNode(nums[i]);
    temp = temp->next;
  }
  return head;
}

// Function to print a linked list
void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Test case: Add (2 -> 4 -> 3) + (5 -> 6 -> 4) = (7 -> 0 -> 8)
  vector<int> num1 = {2, 4, 3};
  vector<int> num2 = {5, 6, 4};

  ListNode* l1 = createList(num1);
  ListNode* l2 = createList(num2);

  cout << "List 1: ";
  printList(l1);
  cout << "List 2: ";
  printList(l2);

  ListNode* result = addTwoNums(l1, l2);

  cout << "Sum: ";
  printList(result);
  cout<<endl;
  cout<<25/2;

  return 0;
}
