// 124. Binary Tree Maximum Path Sum

class  TreeNode {
  int val;
  TreeNode left, right;
  public TreeNode(int n){
    val = n;
  }
}

public class BTMaxPathSum {
  int maxSum;
  private int helper(TreeNode root){
    if(root==null) return 0;
    int ls = Math.max(0, helper(root.left)), rs = Math.max(0, helper(root.right));
    int currSum = root.val+ls+rs;
    maxSum = Math.max(maxSum, currSum);
    return root.val+ Math.max(ls, rs);
  }
  public int maxPathSum(TreeNode root) {
    maxSum = Integer.MIN_VALUE;
    helper(root);
    return maxSum;
  }

  public static void main(String[] args) {
    BTMaxPathSum solver = new BTMaxPathSum();
    TreeNode root1 = new TreeNode(-10);
    root1.left = new TreeNode(9);
    root1.right = new TreeNode(20);
    root1.right.left = new TreeNode(15);
    root1.right.right = new TreeNode(7);

    System.out.println("Max Path Sum (Example 1): " + solver.maxPathSum(root1));
    // Expected: 42 (15 + 20 + 7)

    // Example 2:
    //       1
    //      / \
    //     2   3
    TreeNode root2 = new TreeNode(1);
    root2.left = new TreeNode(2);
    root2.right = new TreeNode(3);

    System.out.println("Max Path Sum (Example 2): " + solver.maxPathSum(root2));
    // Expected: 6 (2 + 1 + 3)

    // Example 3:
    TreeNode root3 = new TreeNode(2);
    root3.left = new TreeNode(-1);

    System.out.println("Max Path Sum (Example 3): " + solver.maxPathSum(root3));
    // Expected: -3
  }
}
