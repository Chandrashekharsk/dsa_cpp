// 876. Middle of the Linked List

public class FindMiddleNode {
  public ListNode middleNode(ListNode head) {
    ListNode slow = head, fast = head;
    while(fast != null && fast.next != null){
      fast = fast.next.next;
      slow = slow.next;
    }
    return slow;
  }
}
