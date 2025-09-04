// 110. Balanced Binary Tree
class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){ val = n; }
}
public class BalancedBT {
  
  private static int helper(TreeNode root){
    if(root == null) return 0;
    return 1+Math.max(helper(root.left),helper(root.right));
  }

  public static boolean isBalanced(TreeNode root) {
    if(root == null) return true;
    int lht = helper(root.left);
    int rht = helper(root.right);
    if(Math.abs(lht-rht)>1) return false;
    return isBalanced(root.left) && isBalanced(root.right);
  }
  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(2);
    root.left.left = new TreeNode(3);
    root.left.left.left = new TreeNode(4);
    root.left.left.right = new TreeNode(4);
    root.left.right = new TreeNode(3);

    root.right = new TreeNode(2);
    System.out.println(isBalanced(root));
  }
}
