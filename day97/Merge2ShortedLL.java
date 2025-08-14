// 21. Merge Two Sorted Lists
class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

public class Merge2ShortedLL {
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    ListNode dummyHead = new ListNode(-1);
    ListNode curr = dummyHead;

    while(list1!= null && list2 != null){
      int val = -1;
      if(list1.val <= list2.val){
        val = list1.val;
        list1 = list1.next;
      }else{
        val = list2.val;
        list2 = list2.next;
      }

      ListNode newNode = new ListNode(val);
      curr.next = newNode;
      curr = newNode;
    }

    while(list1 != null){
      ListNode newNode = new ListNode(list1.val);
      curr.next = newNode;
      curr = newNode;
      list1 = list1.next;
    }
    while(list2 != null){
      ListNode newNode = new ListNode(list2.val);
      curr.next = newNode;
      curr = newNode;
      list2 = list2.next;
    }
    return dummyHead.next;
  }
}
