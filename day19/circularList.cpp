#include<iostream>
#include<vector>
using namespace std;

class CircularList{
  private:
  struct Node{
    int val;
    Node* Next;
    Node(int n): val(n), Next(nullptr){};
  };
  Node* tail;
  int size;

  public:
  CircularList(): tail(nullptr), size(0){};
  
  void push_back(int val){
    Node* newNode = new Node(val);
    if(!tail){
      newNode->Next = newNode;
      tail = newNode;
    }else{
      newNode->Next = tail->Next;
      tail->Next = newNode;
      tail = newNode;
    }
    size++;
  }

  void push_front(int val){
    Node* newNode = new Node(val);
    if(!tail){
      newNode->Next = newNode;
      tail = newNode;
    }else{
      newNode->Next = tail->Next;
      tail->Next = newNode;
    }
    size++;
  }
  
  void pop_back(){
    if(!tail) return;
    if(tail->Next == tail){
      delete tail;
      tail = nullptr;
    }else{
      Node* curr = tail->Next;
      while(curr->Next != tail){
        curr = curr->Next;
      }
      curr->Next = tail->Next;
      delete tail;
      tail = curr;
    }
    size--;
  }
  
  void pop_front(){
    if(!tail) return;
    if(tail->Next == tail){
      delete tail;
      tail = nullptr;
    }else{
      Node* temp = tail->Next;
      tail->Next = tail->Next->Next;
      delete temp;
    }
    size--;
  }

  void insert_at(int index, int val){
    if(!tail) return;
    if(index<0 || index>size) return;

    if(index == 0){
      push_front(val);
    }else if(index == size){
      push_back(val);
    }else{
      Node* newNode = new Node(val);
      Node* curr = tail->Next;
      int count = 0;
      while(count<index-1){
        curr = curr->Next; count++;
      }
      newNode->Next = curr->Next;
      curr->Next = newNode;
      size++;
    }
  }

  void remove_at(int index){
    if(!tail) return;
    if(index<0 || index>size-1) return;

    if(index == 0){
      pop_front();
    }else if(index == size-1){
      pop_back();
    }else{
      Node* curr = tail->Next;
      int count = 0;
      while(count < index-1){
        curr = curr->Next; count++;
      }
      Node* temp = curr->Next;
      curr->Next = curr->Next->Next;
      delete temp;
      size--;
    }
  }

  int in_front() const{
    return tail->Next->val;
  }

  int in_back() const{
    return tail->val;
  }

  int size_of()const {
    return size;
  }

  bool is_empty() const{
    return tail == nullptr;
  }

  void clear(){
    while(!is_empty()){
      pop_front();
    }
  }

  void display () const {
    if(!tail) return;
    Node* curr = tail->Next;
    do{
      cout<< curr->val<<" ";
      curr = curr->Next;
    }while(curr != tail->Next);
    cout<<"\n";
  }
};


int main(){

  CircularList  clist;
  
  clist.push_back(10);
  clist.push_back(20);
  clist.push_back(30);
  clist.push_front(5);
  clist.push_front(1);
  
  cout << "List contents: ";
  clist.display();
  
  cout << "Size of list: " << clist.size_of() << endl;
  
  cout << "Front element: " << clist.in_front() << endl;
  cout << "Back element: " << clist.in_back() << endl;
  
  clist.insert_at(3, 15);  // Insert 15 at index 3
  cout << "After inserting 15 at index 3: ";
  clist.display();
  
  clist.remove_at(2);  // Remove element at index 2
  cout << "After removing element at index 2: ";
  clist.display();
  
  clist.pop_back();
  clist.pop_front();
  cout << "After pop_back and pop_front: ";
  clist.display();
  
  clist.clear();
  cout << "After clearing the list, is it empty? " << (clist.is_empty() ? "Yes" : "No") << endl;
  return 0;
}