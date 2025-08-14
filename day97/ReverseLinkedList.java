// 206. Reverse Linked List

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

public class ReverseLinkedList {
  public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    while(head != null){
      ListNode nextNode = head.next;

      head.next = prev;
      prev = head;
      head = nextNode;
    }
    return prev;
  }
  public static void main(String[] args) {
  
  }
}
