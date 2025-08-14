// 25. Reverse Nodes in k-Group

class ListNode {
  int val;
  ListNode next;

  public ListNode(int n) {
    val = n;
  }
}

public class ReverseKNodes {

  private static void printListNodes(ListNode head) {
    ListNode curr = head;
    while (curr != null) {
      System.out.print(curr.val + " ");
      curr = curr.next;
    }
    System.out.println();
  }

  public static ListNode reverseKGroup(ListNode head, int k){
    if(head == null || k<2) return head;
    int cnt = 0;
    ListNode ptr = head;
    while(ptr != null){
      ++cnt;
      ptr = ptr.next;
    }

    ListNode dummyNode = new ListNode(-1);
    dummyNode.next = head;
    ListNode prev = dummyNode, curr, next;

    while(cnt>= k){
      curr = prev.next;
      next = curr.next;

      for(int i=1; i<k; ++i){
        curr.next = next.next;
        next.next = prev.next;
        prev.next = next;

        next = curr.next;
      }
      cnt-=k;
      prev = curr;
    }

    return dummyNode.next;
  }
  public static void main(String[] args) {
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);
    head.next.next.next.next = new ListNode(5);
    head.next.next.next.next.next = new ListNode(6);

    ListNode newHead = reverseKGroup(head, 3);
    printListNodes(newHead); // Output: 2 1 4 3 5
  }
}
