// 2. Add Two Numbers

public class Add2Nums{
  class ListNode{ 
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {
      this.val = val; 
    }
    ListNode(int val, ListNode next) {
      this.val = val; 
      this.next = next; 
    }
  }

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(-1);
    ListNode curr = dummyHead;
    int carry = 0;

    while(l1 != null || l2 != null){
      int sum = (l1!= null?l1.val:0) + (l2!= null?l2.val:0) + carry;
      carry = sum/10;
      int digit = sum%10;

      ListNode newNode = new ListNode(digit);
      curr.next = newNode;
      curr = newNode;

      if(l1 != null) l1 = l1.next;
      if(l2 != null) l2 = l2.next;
    }

    if(carry>0){
      ListNode newNode = new ListNode(carry);
      curr.next = newNode;
    }

    return dummyHead.next;
  }
}