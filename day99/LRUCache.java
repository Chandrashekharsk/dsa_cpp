// 146. LRU Cache
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;

public class LRUCache {
  // LinkedHashMap<Integer, Integer> m;
  // int cap;

  // public LRUCache(int capacity) {
  //   cap = capacity;
  //   m = new LinkedHashMap<>(capacity,  0.75f, true){
  //     @Override
  //     protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
  //       return size() > cap; // Auto remove eldest when capacity exceeded
  //     }
  //   };
  // }

  // public int get(int key) {
  //   return m.getOrDefault(key, -1);
  // }
  
  // public void put(int key, int value) {
  //   m.put(key, value);
  // }

  // public void printEntries(){
  //   for(Entry<Integer, Integer> e: m.entrySet()){
  //     System.out.println(e.getKey()+" "+e.getValue());
  //   }
  // }

  private static class ListNode{
    int key, val;
    ListNode next, prev;
    public ListNode(int k, int v){
      key = k;
      val = v;
    }
  }
  private int cap;
  private ListNode head, tail;
  private Map<Integer, ListNode> m;
  public LRUCache(int capacity){
    cap = capacity;
    head = new ListNode(0, 0);
    tail = new ListNode(0, 0);
    head.next = tail;
    tail.prev = head;
    m = new HashMap<>();
  }
  
  private void remove(ListNode node){
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }
  private void insertAtHead(ListNode node){
    node.prev = head;
    node.next = head.next;
    head.next.prev = node;
    head.next = node;
  }
  public void put(int key, int value) {
    if(m.containsKey(key)){
      ListNode existingNode = m.get(key);
      existingNode.val = value;
      remove(existingNode);
      insertAtHead(existingNode);
    }else{
      ListNode newNode = new ListNode(key, value);
      insertAtHead(newNode);
      m.put(key, newNode);
      if(m.size() > cap){
        ListNode lru = tail.prev;
        m.remove(lru.key);
        remove(lru);
      }
    }
  }
  public int get (int key){
    if(m.containsKey(key)){
      ListNode existingNode = m.get(key);
      remove(existingNode);
      insertAtHead(existingNode);
      return existingNode.val;
    }
    return -1;
  }

  public static void main(String[] args) {
    LRUCache lc = new LRUCache(3);
    lc.put(1, 11);
    lc.put(2, 12);
    lc.put(3, 13);
    // lc.printEntries();
    lc.put(4, 14);
    System.out.println(lc.get(3));
    // lc.printEntries();
  }
}