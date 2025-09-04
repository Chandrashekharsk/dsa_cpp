// 104. Maximum Depth of Binary Tree
class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}

public class MaxDepthOfBT{

  int helper(TreeNode root){
    if(root == null) return 0;
    return 1 + Math.max(helper(root.left), helper(root.right));
  }
  public int maxDepth(TreeNode root) {
    return helper(root);
  }
  public static void main(String[] args) {
  MaxDepthOfBT obj = new MaxDepthOfBT();
  // Sample input: Constructing a binary tree
  //      1
  //     / \
  //    2   3
  //   / 
  //  4
  TreeNode root = new TreeNode(1);
  root.left = new TreeNode(2);
  // root.right = new TreeNode(3);
  // root.left.left = new TreeNode(4);
  int depth = obj.maxDepth(root);
  System.out.println("Max Depth: " + depth); // Output should be 3
  }
}