// 572. Subtree of Another Tree

class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}

public class SubTree {
  private boolean helper(TreeNode root, TreeNode subRoot){
    if(root==null && subRoot == null) return true;
    if(root == null || subRoot == null) return false;
    if (root.val != subRoot.val) return false;
    return helper(root.left, subRoot.left) && helper(root.right, subRoot.right);
  }
  public boolean isSubtree(TreeNode root, TreeNode subRoot) {
    if (root == null && subRoot != null) return false;
    if(helper(root, subRoot)) return true;
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
  }

  public static void main(String[] args) {
  SubTree sb = new SubTree();
  // Sample input: Constructing a binary tree and a subtree
  // Tree:      3
  //           / \
  //          4   5
  //         / \
  //        1   2
  TreeNode root = new TreeNode(3);
  root.left = new TreeNode(4);
  root.right = new TreeNode(5);
  root.left.left = new TreeNode(1);
  root.left.right = new TreeNode(2);
  // root.left.right.right = new TreeNode(7);

  // Subtree:   4
  //           / \
  //          1   2
  TreeNode subRoot = new TreeNode(4);
  subRoot.left = new TreeNode(1);
  subRoot.right = new TreeNode(2);

  boolean result = sb.isSubtree(root, subRoot);
  System.out.println("Is subRoot a subtree of root? " + result); // Output should be true
  }
}
