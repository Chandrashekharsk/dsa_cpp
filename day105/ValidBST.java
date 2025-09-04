// 98. Validate Binary Search Tree
public class ValidBST {
  private boolean helper(TreeNode root, Long minVal, Long maxVal) {
    if (root == null) return true;
    if(root.val >= maxVal || root.val <= minVal) return false;

    return helper(root.left, (long) minVal, (long) root.val) && helper(root.right, (long) root.val, (long) maxVal);
  }

  public boolean isValidBST(TreeNode root){
    return helper(root, Long.MIN_VALUE, Long.MAX_VALUE);
  }

  public static void main(String[] args) {
    // ✅ Test 1: Valid BST
    TreeNode root1 = new TreeNode(2);
    root1.left = new TreeNode(1);
    root1.right = new TreeNode(3);

    ValidBST solver = new ValidBST();
    System.out.println("Tree 1 is valid BST? → " + solver.isValidBST(root1)); // true

    // ✅ Test 2: Invalid BST
    TreeNode root2 = new TreeNode(5);
    root2.left = new TreeNode(1);
    root2.right = new TreeNode(7);
    root2.right.left = new TreeNode(3); // ❌ invalid, should be >5
    root2.right.right = new TreeNode(8);

    System.out.println("Tree 2 is valid BST? → " + solver.isValidBST(root2)); // false
  }
}
