
// 716. MaxStack
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class MaxStack {
  class ListNode {
    int val;
    ListNode prev, next;

    public ListNode(int n) {
      val = n;
    }
  }
  ListNode head, tail;
  private TreeMap<Integer, List<ListNode>> tm;

  private void addNode(ListNode node) {
    tail.prev.next = node;
    node.prev = tail.prev;
    node.next = tail;
    tail.prev = node;
  }

  private void removeNode(ListNode node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }

  // CONSTRUCTOR
  public MaxStack() {
    tm = new TreeMap<>();
    head = new ListNode(0);
    tail = new ListNode(0);
    head.next = tail;
    tail.prev = head;
  }

  public void push(int x) {
    ListNode newNode = new ListNode(x);
    addNode(newNode);
    tm.computeIfAbsent(x, f -> new ArrayList<>()).add(newNode);
  }

  public int top() {
    return tail.prev.val;
  }

  public int peekMax() {
    return tm.lastKey();
  }

  public int pop() {
    ListNode node = tail.prev;
    int key = node.val;
    List<ListNode> list = tm.get(key);
    list.remove(list.size() - 1);
    if(list.isEmpty()) tm.remove(key);
    removeNode(node);
    return key;
  }

  public int popMax() {
    Map.Entry<Integer, List<ListNode>> entry = tm.lastEntry();
    int key = entry.getKey();
    List<ListNode> nodes = entry.getValue();
    ListNode removedNode = nodes.remove(nodes.size() - 1);
    if (nodes.isEmpty())
      tm.remove(key);
    removeNode(removedNode);
    return key;
  }
}
