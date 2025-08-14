// 234. Palindrome Linked List

public class PalindromeLinkedList {
  static class ListNode{
    int val;
    ListNode next;
    public ListNode(int n){
      val = n; 
      next = null;
    }
  }

  private static ListNode reverse(ListNode node){
    ListNode prev = null;
    while(node != null){
      ListNode nextNode = node.next;
      node.next = prev;
      prev = node;
      node = nextNode;
    }
    return prev;
  }
  public static boolean isPalindrome(ListNode head) {
    // approach 1
    // ListNode temp = head, curr = head;
    // StringBuilder sb = new StringBuilder();
    // while(temp!= null){
    //   sb.append(Integer.toString(temp.val));
    //   temp = temp.next;
    // }
    // String s = sb.toString();
    // int idx = s.length()-1;

    // while (curr != null && idx>=0) {
    //   if(curr.val != s.charAt(idx) -'0') return false;
    //   curr = curr.next;
    //   --idx;
    // }
    // return true;


    // approach 2
    if(head == null || head.next == null) return true;

    ListNode slow = head, fast = head;
    while(fast != null && fast.next != null){
      fast = fast.next.next;
      slow = slow.next;
    }

    ListNode secondHalf = reverse(slow);
    ListNode firstHalf = head;

    while(secondHalf!= null){
      if(firstHalf.val != secondHalf.val) return false;
      firstHalf = firstHalf.next;
      secondHalf =  secondHalf.next;
    }
    return true;
  }

  public static void main(String[] args) {
    ListNode head = new ListNode(1);
    // head.next = new ListNode(2);
    // head.next.next = new ListNode(3);
    // head.next.next.next = new ListNode(1);

    head.next = new ListNode(3);
    head.next.next = new ListNode(1);
    System.out.println(isPalindrome(head));
  }
}
