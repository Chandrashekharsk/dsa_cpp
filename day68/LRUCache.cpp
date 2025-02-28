// 146. LRU Cache
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class LRUCache{
  public:
  class ListNode{
    public:
    int key, val;
    ListNode* next;
    ListNode* prev;
    ListNode(int k, int v): key(k), val(v), next(nullptr), prev(nullptr){};
  };
  ListNode* head;
  ListNode* tail;
  unordered_map<int, ListNode*> m;
  int capacity;

  LRUCache(int cap){
    capacity = cap;
    head = new ListNode(-1, -1);
    tail = new ListNode(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void addNode(ListNode* newNode){
    ListNode* nextNode = head->next;
    
    newNode->next = nextNode;
    newNode->prev = head;

    head->next =newNode;
    nextNode->prev = newNode;
  };
  void removeNode(ListNode* targetNode){
    ListNode* prevNode = targetNode->prev;
    ListNode* nextNode = targetNode->next;
    
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  };

  void put(int key, int val){
    if(m.find(key) != m.end()){
      ListNode* existingNode = m[key];
      removeNode(existingNode);
      delete existingNode;
    }else{
      if(m.size() == capacity){
        ListNode* leastNode = tail->prev;
        m.erase(leastNode->key);
        removeNode(leastNode);
        delete leastNode;
      }
    }
    ListNode* newNode = new ListNode(key, val);
    addNode(newNode);
    m[key] = newNode;
  } 
  int get(int key){
    if(m.find(key) == m.end()) return -1;
    ListNode* accessedNode = m[key];
    removeNode(accessedNode);
    addNode(accessedNode);
    return accessedNode->val;
  }

  void displayElements(){
    for(auto it = m.begin(); it != m.end(); ++it){
      cout<<it->first<<" : "<<it->second->val<<" -> ";
    }
    cout<<"NULL"<<endl;
  }
};

int main(){
  LRUCache obj =  LRUCache(2);
  obj.put(1, 5);
  obj.put(7, 15);
  cout<<obj.get(1)<<endl;
  cout<<obj.get(7)<<endl;
  obj.displayElements();
  obj.put(8, 25);
  obj.displayElements();
  cout<<obj.get(7)<<endl;

  return 0;
}