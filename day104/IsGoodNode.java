// 1448. Count Good Nodes in Binary Tree
class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}

public class IsGoodNode {
  private int cnt = 0;
  
  private void helper(TreeNode root, int maxPathVal){
    if(root == null) return;
    if(root.val >= maxPathVal) ++cnt;
    maxPathVal = Integer.max(maxPathVal, root.val);

    helper(root.left, maxPathVal);
    helper(root.right, maxPathVal);
  }
  
  public int goodNodes(TreeNode root) {
    if(root == null) return cnt;
    int maxPathVal = root.val;
    helper(root, maxPathVal);
    return cnt;
  }
  public static void main(String[] args) {
    // Sample input: Constructing a binary tree
    //      3
    //     / \
    //    1   4
    //         \
    //          5
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(1);
    root.right = new TreeNode(4);
    root.right.right = new TreeNode(3);

    IsGoodNode obj = new IsGoodNode();
    int result = obj.goodNodes(root);
    System.out.println("Number of good nodes: " + result); // Output should be 3
  }
}
