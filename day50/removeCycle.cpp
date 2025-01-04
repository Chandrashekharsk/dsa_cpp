// 141. Linked List Cycle
#include<iostream>
#include<vector>
using namespace std;


// struct Node{
//   int data;
//   Node* next;
//   Node(int val): data(val), next(nullptr){};
// };

class Node{
  public:
  int data;
  Node* next;

  // Node(int val): data(val), next(nullptr){};
  Node(int val){
    data = val;
    next = nullptr;
  }
};


class List{
  Node* head;
  Node* tail;
  public:
    List(){
      head = tail = nullptr;
    }

    void pushFront(int val){
      Node* newNode = new Node(val);
      if(head == nullptr){
        head = tail = newNode;
      }else{
        newNode->next = head;
        head = newNode;
      }
    }
    void pushBack(int val){
      Node* newNode = new Node(val);
      if(head == nullptr){
        head = tail = newNode;
      }else{
        tail->next = newNode;
        tail = newNode;
      }
    }
    void popFront(){
      if(head == nullptr){
        cout<<"List is already empty";
      }else{
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
      }
    }
    void popBack(){
      if(head == nullptr){
        cout<<"List is already empty";
      }else{
        Node* temp = head;
        while(temp->next != tail){
          temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
      }
    }

    void insert(int val, int idx){
      Node* newNode = new Node(val);
      if(idx<0){
        cout<<"Invalid index value";
        return;
      }
      if(idx==0){
        pushFront(val);
        return;
      }
      if(head == nullptr){
        cout<<"list is empty\n";
        return;
      }
      Node* temp = head;
      for(int i=0; i<idx-1; ++i){
        if(temp == nullptr){
          cout<<"Index value out of bounds\n";
          return;
        }
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
    }

    void printLL(){
      Node* temp = head;
      while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
      }
      cout<<"nullptr"<<endl;
    }

    int search(int key){
      if(head == nullptr) return -1;

      Node* temp = head;
      int idx = 0;
      while( temp != nullptr){
        if(temp->data == key){
          return idx;
        };
        temp = temp->next;
        ++idx;
      }
      return -1;
    }

    void reverse(){
      if(head == nullptr) return;
      Node* prev = nullptr;
      Node* curr = head;
      Node* next = nullptr;

      while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      tail = head;
      head = prev;
    }
    void getMiddleNode(){
      Node* slow = head;
      Node* fast = head;
      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }
      cout<<slow->data<<endl;
    }

    bool hasCycle(){
      if(head == nullptr || head->next == nullptr) return false;
      Node* slow = head;
      Node* fast = head;
      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
      }
      return false;
    }

    void createCycle(){
      if(head == nullptr) return;
      tail->next = head;
    }

    Node* detectCycle(){
      Node* slow = head;
      Node* fast = head;
      bool isCycle = false;

      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
          isCycle = true;
          break;
        }
      }

      if(isCycle == false) return nullptr;

      slow = head;
      while(fast != slow){
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
    }

    void removeCycle(){
      Node* slow = head;
      Node* fast = head;
      bool isCycle = false;

      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
          isCycle = true;
          break;
        }
      }

      if(isCycle == false) return;

      slow = head;
      Node* prev = nullptr;
      while(fast != slow){
        prev = fast;
        fast = fast->next;
        slow = slow->next;
      }
      prev->next = nullptr;
    }

};



int main(){

  List ll;

  ll.pushFront(3);
  ll.pushFront(2);
  ll.pushFront(1);
  ll.pushBack(4);
  ll.popFront();
  ll.popBack();
  ll.insert(1, 1);
  ll.insert(11, 10);
  cout<<ll.search(6)<<endl;
  cout<<ll.search(3)<<endl;
  ll.reverse();
  ll.insert(4,0);


  ll.printLL();
  ll.getMiddleNode();
  ll.createCycle();
  // cout<<ll.hasCycle();
  Node* cycleStartNode = ll.detectCycle();
  cout<<cycleStartNode->data;


  return 0;
}