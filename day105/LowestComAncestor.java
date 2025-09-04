// 236. Lowest Common Ancestor of a Binary Tree
class TreeNode {
  int val;
  TreeNode left, right;
  public TreeNode(int n) {
    val = n;
  }
}

public class LowestComAncestor {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || root.val == p.val || root.val == q.val)
      return root;
    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
    if (left != null && right != null)
      return root;
    return left != null ? left : right;
  }

  public static void main(String[] args) {
    /*
     * Sample Tree:
     *     3
     *   /   \
     *   5    1
     *  / \  / \
     * 6   2 0   8
     *    / \
     *    7 4
     * ✅ LCA(5, 1) → 3
     * ✅ LCA(6, 4) → 5
     * ✅ LCA(7, 8) → 3
     */

    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(5);
    root.right = new TreeNode(1);
    root.left.left = new TreeNode(6);
    root.left.right = new TreeNode(2);
    root.right.left = new TreeNode(0);
    root.right.right = new TreeNode(8);
    root.left.right.left = new TreeNode(7);
    root.left.right.right = new TreeNode(4);

    LowestComAncestor solver = new LowestComAncestor();

    TreeNode lca1 = solver.lowestCommonAncestor(root, root.left, root.right);
    System.out.println("LCA of 5 and 1 → " + lca1.val); // Expected 3

    TreeNode lca2 = solver.lowestCommonAncestor(root, root.left.left, root.left.right.right);
    System.out.println("LCA of 6 and 4 → " + lca2.val); // Expected 5

    TreeNode lca3 = solver.lowestCommonAncestor(root, root.left.right.left, root.right.right);
    System.out.println("LCA of 7 and 8 → " + lca3.val); // Expected 3
  }
}