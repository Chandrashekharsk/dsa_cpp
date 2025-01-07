// 21. Merge Two Sorted Lists
#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head = new ListNode(-1);
      ListNode* temp = head;
      
      while(list1 != nullptr && list2 != nullptr){
        if(list1->val<list2->val){
          temp->next = list1;
          list1 = list1->next;
        }else{
          temp->next = list2;
          list2 = list2->next;
        }
        temp = temp->next;
      }
      while(list1 != nullptr){
        temp->next = list1;
        list1 = list1->next;
        temp = temp->next;
      }
      while(list2 != nullptr){
        temp->next = list2;
        list2 = list2->next;
        temp = temp->next;
      }
      return head->next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
  if (size == 0) return nullptr;
  ListNode* head = new ListNode(arr[0]);
  ListNode* current = head;
  for (int i = 1; i < size; i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}

int main() {
  // Example input
  int arr1[] = {1, 2, 4};
  int arr2[] = {1, 3, 4};

  ListNode* list1 = createList(arr1, 3);
  ListNode* list2 = createList(arr2, 3);

  Solution solution;
  ListNode* mergedList = solution.mergeTwoLists(list1, list2);

  // Print the merged list
  printList(mergedList);

  return 0;
}
