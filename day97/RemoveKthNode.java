// 19. Remove Nth Node From End of List
import java.util.ArrayList;
import java.util.List;


class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

public class RemoveKthNode {
  public ListNode removeNthFromEnd(ListNode head, int n) {
    // approach 1
    // if(head == null)return head;
    // List<ListNode> list = new ArrayList<>();
    // ListNode curr = head;
    // while(curr != null){
    //   list.add(curr);
    //   curr = curr.next;
    // }

    // int tarIdxPrevNode = list.size()-n-1;
    // if(tarIdxPrevNode < 0) return head.next;
    // ListNode prev = list.get(tarIdxPrevNode);
    // prev.next = prev.next.next;
    // return head;

    // approach 2
    ListNode dummyNode = new ListNode(-1);
    dummyNode.next = head;
    ListNode slow = dummyNode, fast = dummyNode;

    while(fast != null && n>=0){
      fast = fast.next;
      --n;
    }

    while(fast != null){
      slow = slow.next;
      fast = fast.next;
    }
    if(slow.next != null) slow.next = slow.next.next;
    return dummyNode.next;
  }
}
