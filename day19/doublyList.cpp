
#include<iostream>
#include<vector>
using namespace std;

class List{
  private:
  struct Node{
    int val;
    Node* Next;
    Node* Prev;
    Node(int n): val(n), Next(nullptr), Prev(nullptr){};
  };
  int size;
  Node* head;
  Node* tail;

  public:
  List(): head(nullptr), tail(nullptr), size(0){};

  void push_back(int n){
    Node* newNode = new Node(n);
    if(!head){
      head = tail = newNode;
    }else{
      tail->Next = newNode;
      newNode->Prev = tail;
      tail = newNode;
    }
    size++;
  };

  void push_front(int n){
    Node* newNode = new Node(n);
    if(head == nullptr){
      head = tail = newNode;
    }else{
      newNode->Next = head;
      head->Prev = newNode;
      head = newNode;
    }
    size++;
  };

  void pop_back (){
    if(head == nullptr) return;
    else if( head == tail){
      delete head;
      head = tail = nullptr;
    }else{
      Node* temp = tail;
      tail = tail->Prev;
      tail->Next = nullptr;
      delete temp;
    }
    size--;
  };

  void pop_front(){
    if(head == nullptr) return;
    else if(head == tail){
      delete head;
      head = tail = nullptr;
    }else{
      Node* temp = head;
      head = head->Next;
      head->Prev = nullptr;
      delete temp;
    }
    size--;
  }

  void insert_at(int index, int val){
    if(index>size || index<0) return;
    if(index == 0){
      push_front(val);
    }else if(index == size){
      push_back(val);
    }else{
      Node* newNode = new Node(val);
      Node* curr = head;
      int count = 0;
      while(count < index-1){
        curr = curr->Next; count++;
      }
      newNode->Prev = curr;
      newNode->Next =  curr->Next;
      curr->Next->Prev = newNode;
      curr->Next = newNode;
      size++;
    }

  }
  void remove_at(int index){
    if(index>=size || index<0 || head == nullptr ) return;
    if(index == 0) pop_front();
    else if(index == size-1) pop_back();
    else{
      Node* curr = head;
      int count = 0;
      while(count<index-1){
        curr= curr->Next; count++;
      }
      Node* temp = curr->Next->Next;
      curr->Next = curr->Next->Next;
      temp->Prev = curr;
      size--;
    }
  }

  int size_of() const {
    return size;
  }

  bool is_empty() const{
    return head == nullptr;
  }

  int in_back() const{
    if(!head) throw out_of_range("List is empty");
    return tail->val;
  }

  int in_front() const{
    if(!head) throw out_of_range("List is empty");
    return head->val;
  }
  
  void clear() {
    while (head) pop_front();
  }

  void display() const {
    if(!head) return;
    Node* curr = head;
    while(curr != nullptr){
      cout<< curr->val<<" ";
      curr = curr->Next;
    }
  }
  void displayReverse() const {
    if(!head) return;
    Node* curr = tail;
    while(curr != nullptr){
      cout<< curr->val;
      curr = curr->Prev;
    }
  }
};

int main(){

  List dlist;
  dlist.push_back(3);
  dlist.push_back(4);
  dlist.push_back(5);
  dlist.push_front(2);
  dlist.push_front(1);

  cout << dlist.size_of() << " \n";
  dlist.display(); cout << "\n";

  dlist.pop_back();
  dlist.pop_front();
  dlist.display(); cout << "\n";
  cout << dlist.in_front() << "\n";
  cout << dlist.in_back() << "\n";

  dlist.insert_at(0, 1);
  dlist.display(); cout << "\n";
  dlist.insert_at(3, 50);
  dlist.display(); cout << "\n";
  dlist.remove_at(3);
  dlist.display(); cout << "\n";
  
  cout << dlist.is_empty() << "\n";
  dlist.clear();
  cout << dlist.is_empty() << "\n";

  return 0;
}