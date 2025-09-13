// 133. Clone Graph
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class Node {
  public int val;
  public List<Node> neighbors;

  public Node() {
    val = 0;
    neighbors = new ArrayList<Node>();
  }

  public Node(int _val) {
    val = _val;
    neighbors = new ArrayList<Node>();
  }

  public Node(int _val, ArrayList<Node> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
}

public class CloneGraph {
  private Map<Node, Node> m = new HashMap<>();

  public Node cloneGraph(Node node) {
    if(node == null) return null;
    if(m.containsKey(node)) return m.get(node);

    Node cloneNode = new Node(node.val);
    m.put(node, cloneNode);

    for(Node n: node.neighbors) cloneNode.neighbors.add(cloneGraph(n));
    return cloneNode;
  }

  public static void main(String[] args) {
    // Create graph manually
    Node node1 = new Node(1);
    Node node2 = new Node(2);
    Node node3 = new Node(3);
    Node node4 = new Node(4);

    // Connect nodes (undirected graph)
    node1.neighbors.add(node2);
    node1.neighbors.add(node4);

    node2.neighbors.add(node1);
    node2.neighbors.add(node3);

    node3.neighbors.add(node2);
    node3.neighbors.add(node4);

    node4.neighbors.add(node1);
    node4.neighbors.add(node3);

    // Clone graph
    CloneGraph cg = new CloneGraph();
    Node clonedGraph = cg.cloneGraph(node1);

    // Print to verify (just showing values of cloned neighbors of node1)
    System.out.print("Cloned Node 1 neighbors: ");
    for (Node n : clonedGraph.neighbors) {
      System.out.print(n.val + " ");
    }
  }
}