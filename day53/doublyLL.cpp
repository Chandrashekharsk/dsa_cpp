#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;
  Node(int val){
    this->data = val;
    this->next = this->prev = nullptr;
  }
};

class DoublyList{
  Node* head;
  Node* tail;
  public:
  DoublyList(){
    this->head = this->tail = nullptr;
  }

  void push_front(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
      head = tail = newNode;
      return;
    }else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      return;
    }
  }
  
  void push_back(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
      head = tail = newNode;
      return;
    }else{
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
      return;
    }
  }
  
  void printList(){
    Node* curr = head;
    if(head == nullptr){
      cout<<"List is empty";
      return;
    }

    cout<<"null<->";
    while(curr != nullptr){
      cout<<curr->data<<"<->";
      curr = curr->next;
    }
    cout<<"null";
  }

  void pop_front(){
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if(head != nullptr) head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
  }

  void pop_back(){
    if(head == nullptr) return;
    Node* temp = tail;
    tail = tail->prev;
    if(tail != nullptr) tail->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }
};

int main(){

  DoublyList dll;
  dll.push_front(3);
  dll.push_back(5);
  dll.push_back(9);
  dll.pop_front();
  dll.pop_back();

  dll.printList();


  return 0;
}