// 138. Copy List with Random Pointer
import java.util.HashMap;
import java.util.Map;

class ListNode {
  int val;
  ListNode next;
  ListNode random;

  public ListNode(int val) {
    this.val = val;
    this.next = null;
    this.random = null;
  }
}

public class CopyLL {

  public ListNode copyRandomList(ListNode head) {
    Map<ListNode, ListNode> m  = new HashMap<>();
    ListNode ptr= head;
    while(ptr != null){
      m.put(ptr, new ListNode(ptr.val));
      ptr = ptr.next;
    }

    ptr = head;
    while(ptr != null){
      m.get(ptr).next = m.get(ptr.next);
      m.get(ptr).random = m.get(ptr.random);
      ptr = ptr.next;
    }
    return m.get(head);
  }

  // Helper method to print list with random pointers
  private static void printList(ListNode head) {
    ListNode curr = head;
    while (curr != null) {
      int randomVal = (curr.random != null) ? curr.random.val : -1;
      System.out.print("[" + curr.val + ", random:" + randomVal + "] -> ");
      curr = curr.next;
    }
    System.out.println("null");
  }

  public static void main(String[] args) {
    // Create original list: 1 -> 2 -> 3
    ListNode n1 = new ListNode(1);
    ListNode n2 = new ListNode(2);
    ListNode n3 = new ListNode(3);
    n1.next = n2;
    n2.next = n3;

    // Assign random pointers
    n1.random = n3; // 1's random -> 3
    n2.random = null; // 2's random -> 1
    n3.random = n2; // 3's random -> 2

    System.out.println("Original list:");
    printList(n1);

    CopyLL cll = new CopyLL();
    ListNode copiedHead = cll.copyRandomList(n1);

    System.out.println("Copied list:");
    printList(copiedHead);
  }
}
