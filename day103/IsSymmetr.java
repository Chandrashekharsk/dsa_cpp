// 101. Symmetric Tree
class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}
public class IsSymmetr {

  private boolean helper(TreeNode left, TreeNode right){
    if(left == null && right == null) return true;
    if(left == null || right == null) return false;
    return left.val == right.val && helper(left.left, right.right) && helper(left.right, right.left);
  }

  public boolean isSymmetric(TreeNode root) {
    if(root == null) return true;
    return helper(root.left, root.right);
  }

  public static void main(String[] args) {
    /*
     * Sample symmetric tree:
     *      1
     *     / \
     *    2   2
     *   / \ / \
     *  3  4 4  3
     *           \
     *            9
     */            
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    root.left.left = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.right.left = new TreeNode(4);
    root.right.right = new TreeNode(3);
    root.right.right = new TreeNode(9);

    IsSymmetr checker = new IsSymmetr();
    boolean result = checker.isSymmetric(root);
    System.out.println("Is tree symmetric? " + result);
  }

  // ...existing code...
}
