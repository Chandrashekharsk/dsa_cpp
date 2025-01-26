class Node {
  int data;
  Node left;
  Node right;

  public Node(int n) {
    this.data = n;
    this.left = null;
    this.right = null;
  }
}

public class BinaryTree {
  public static void main(String[] args) {
    // Creating the root node
    Node root = new Node(1);

    // Adding child nodes
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.right = new Node(5);

    // Printing the tree structure
    System.out.println("Root: " + root.data);
    System.out.println("Left child of root: " + root.left.data);
    System.out.println("Right child of root: " + root.right.data);
    System.out.println("Right child of left node: " + root.left.right.data);
  }
}
