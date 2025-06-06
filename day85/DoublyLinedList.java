class ListNode{
  int val;
  ListNode prev, next;
  public ListNode(int n){
    this.val = n;
    this.prev = this.next = null;
  }
}

public class DoublyLinedList {
  ListNode head, tail;

  public void insertAtFirst(int n){
    ListNode newNode = new ListNode(n);
    if(head != null){
      head.prev = newNode;
    }
    head = newNode;
  }

  public void insertAtLast(int n){
    ListNode newNode = new ListNode(n);
    if(tail != null) tail.next = newNode;
    tail = newNode;
  }

  public void deleteFirst(){
    if(head != null) head = head.next;
  }
  public void deleteLast(){
    if(tail != null) tail = tail.prev;
  }
}
