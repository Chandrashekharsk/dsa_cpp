// 114. Flatten Binary Tree to Linked List

class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){ val = n; }
}


public class FlattenTreeToLL {
  private TreeNode helper(TreeNode root){
    if(root == null || root.left == null && root.right == null) return root;
    
    TreeNode leftTail = helper(root.left);
    TreeNode rightTail = helper(root.right);

    if(leftTail != null){
      leftTail.right = root.right;
      root.right = root.left;
      root.left = null;
    }
    return (rightTail == null)? leftTail: rightTail;
  }
  public void flatten(TreeNode root) {
    helper(root);
  }
}
