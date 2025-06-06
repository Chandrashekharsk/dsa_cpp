import java.util.List;

class ListNode {
  int val;
  ListNode next;
  public ListNode(int n){
    this.val = n;
    this.next = null;
  }
}

public class LinkedList {
  private ListNode head;

  public void insert(int data){
    ListNode newNode = new ListNode(data);
    if(head==null){
      head = newNode;
      return;
    }
    ListNode curr = head;
    while(curr.next != null){
      curr = curr.next;
    }
    curr.next = newNode;
  }

  public boolean isEmpty(){
    return head == null;
  }

  public void delete(int key){
    if(head==null) return;
    if(head.val == key){
      head = head.next;
      return;
    }
    ListNode curr = head;
    while(curr.next != null && curr.val != key) curr = curr.next;
    if(curr.next != null) curr = curr.next;
  }

  public void display (){
    ListNode curr  = head;
    while(curr != null){
      System.out.print(curr.val);
      System.out.print("->");
      curr = curr.next;
    }
  }
  
  public static void main(String[] args) {
    LinkedList list = new LinkedList();
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.delete(2);
    list.insert(5);
    list.display();
  }
}