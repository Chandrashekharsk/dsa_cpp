// 543. Diameter of Binary Tree
public class DiameterOfBT {
  private int maxDiameter = 0;
  private int helper(TreeNode root){
    if(root==null) return 0;

    int leftHt = helper(root.left), rightHt = helper(root.right);
    maxDiameter = Math.max(maxDiameter, rightHt+leftHt);

    return Math.max(leftHt, rightHt)+1;
  }

  public int diameterOfBinaryTree(TreeNode root) {
    if(root==null) return 0;
    helper(root);
    return maxDiameter;
  }

  // Sample input and main method
  public static void main(String[] args) {
    /*
     * Sample tree:
     *      1
     *     / \
     *    2   3
     *   / \
     *  4   5
     * Diameter is 3 (path: 4-2-1-3 or 5-2-1-3)
     */
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);

    // TreeNode root = new TreeNode(1);
    // root.left = new TreeNode(2);
    // root.right = new TreeNode(3);
    // root.left.left = new TreeNode(4);
    // root.left.right = new TreeNode(5);

    DiameterOfBT tree = new DiameterOfBT();
    int diameter = tree.diameterOfBinaryTree(root);
    System.out.println("Diameter of Binary Tree: " + diameter);
  }
}
