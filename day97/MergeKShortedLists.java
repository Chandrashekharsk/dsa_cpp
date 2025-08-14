// 23. Merge k Sorted Lists
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap;

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

public class MergeKShortedLists {
  public ListNode mergeKLists(ListNode[] lists) {
    // approach 1
    // Map<Integer, Integer> tm = new TreeMap<>();

    // for(ListNode head: lists){
    //   ListNode curr = head;
    //   while(curr != null){
    //     tm.put(curr.val, tm.getOrDefault(curr.val, 0)+1);
    //     curr = curr.next;
    //   }
    // }
    // ListNode dummyNode = new ListNode(-1);
    // ListNode curr = dummyNode;
    // for(Map.Entry<Integer,Integer> entry: tm.entrySet()){
    //   int val = entry.getKey();
    //   for(int i=0; i<entry.getValue();++i){
    //     ListNode newNode = new ListNode(val);
    //     curr.next = newNode;
    //     curr = newNode;
    //   }
    // }
    // return dummyNode.next;

    // approach 2
    PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b)->a.val-b.val);
    for(ListNode head: lists){
      if(head != null) pq.add(head);
    }
    ListNode dummListNode = new ListNode(-1);
    ListNode curr = dummListNode;

    while(!pq.isEmpty()){
      curr.next = pq.poll();
      curr = curr.next;
      if(curr.next != null) pq.add(curr.next);
    }
    return dummListNode.next;
  }
}
