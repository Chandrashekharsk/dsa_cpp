// 226. Invert Binary Tree
class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}

public class InvertBT {
  private void helper(TreeNode root){
    if(root == null) return;

    TreeNode tempNode = root.left;
    root.left = root.right;
    root.right = tempNode;
    
    helper(root.left);
    helper(root.right);
  }

  public TreeNode invertTree(TreeNode root) {
    if(root == null) return root;
    helper(root);
    return root;
  }

  // Helper to print tree in-order
  private static void printInOrder(TreeNode root) {
    if (root == null) return;
    printInOrder(root.left);
    System.out.print(root.val + " ");
    printInOrder(root.right);
  }

  // Sample input and main method
  public static void main(String[] args) {
    /*
     * Sample tree:
     *      1
     *     / \
     *    2   3
     *   / \   \
     *  4   5   6
     * Inverted tree should swap left/right values
     */
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.right = new TreeNode(6);

    System.out.print("Original tree (in-order): ");
    printInOrder(root);
    System.out.println();

    InvertBT inverter = new InvertBT();
    inverter.invertTree(root);

    System.out.print("Inverted tree (in-order): ");
    printInOrder(root);
    System.out.println();
  }
}
