// 143. Reorder List
import java.util.ArrayList;
import java.util.List;

class ListNode{
  int val;
  ListNode next;
  public ListNode(int n){ val = n;}
}

public class ReorderLL{

  private ListNode reverse(ListNode head){
    ListNode prev = null;
    ListNode curr= head;
    while(curr != null){
      ListNode nextNode = curr.next;
      curr.next = prev;

      prev = curr;
      curr = nextNode;
    }
    return prev;
  }
  public void reorderList(ListNode head) {

    // approach 1
    // if(head == null || head.next == null) return;
    // ListNode curr = head;
    // List<ListNode> l = new ArrayList<>();
    // while(curr != null){
    //   l.add(curr);
    //   curr = curr.next;
    // }

    // int st = 1, end = l.size()-1;
    // curr = head;
    // while(st<=end){
    //   curr.next = l.get(end);
    //   curr = curr.next;
      
    //   if(st!= end){
    //     curr.next = l.get(st);
    //     curr = curr.next;
    //   }
    //   ++st; --end;
    // }
    // curr.next = null;

    
    // approach 2
    if(head == null || head.next == null) return;
    ListNode slow = head, fast = head;
    while(fast != null && fast.next != null){
      slow = slow.next;
      fast = fast.next.next;
    }
    ListNode reverListNodeHead = reverse(slow.next);
    slow.next = null;
    ListNode first = head, second = reverListNodeHead;
    while(second != null ){
      ListNode temp1 = first.next;
      ListNode temp2 = second.next;
      first.next = second;
      second.next = temp1;
      
      first = temp1;
      second = temp2;
    }
  }
}