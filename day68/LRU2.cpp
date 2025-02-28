#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
 private:
  int capacity;
  list<pair<int, int>> dll; // Doubly linked list (stores {key, value})
  unordered_map<int, list<pair<int, int>>::iterator> m; // Maps key -> iterator in the list

 public:
  LRUCache(int cap){ 
    capacity = cap;
  }

  int get(int key) {
    if (m.find(key) == m.end()) return -1;  // Key not found

    // Move accessed node to front (most recently used)
    dll.splice(dll.begin(), dll, m[key]);

    return m[key]->second;  // Return value
  }

  void put(int key, int value) {
    // If key already exists, remove old entry
    if (m.find(key) != m.end()) {
      dll.erase(m[key]);
    } else if (dll.size() == capacity) {  // Cache full, remove least recently used
      int lruKey = dll.back().first;  // Get LRU key
      m.erase(lruKey);               // Remove from map
      dll.pop_back();                 // Remove from list
    }

    // Insert new key-value pair at front
    dll.push_front({key, value});
    m[key] = dll.begin();
  }

  void display() {
    for (auto it : dll) {
      cout << it.first << ":" << it.second << " -> ";
    }
    cout << "NULL\n";
  }
};

int main() {
  LRUCache obj(2);
  obj.put(1, 5);
  obj.put(7, 15);
  cout << obj.get(7) << endl;  // 15
  cout << obj.get(1) << endl;  // 5
  obj.display();               // 1:5 -> 7:15 -> NULL

  obj.put(8, 20);
  obj.display();  // 8:20 -> 1:5 -> NULL (7 is removed since it was LRU)

  cout << obj.get(7) << endl;  // -1 (not found)

  return 0;
}
