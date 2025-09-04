// 100. Same Tree

public class SameTree {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if(p==null && q == null) return true;
    if(p==null || q == null) return false;
    return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }
  public static void main(String[] args) {
  // Sample input: Constructing two binary trees
  // Tree 1:   1
  //          / \
  //         2   3
  TreeNode p = new TreeNode(1);
  p.left = new TreeNode(2);
  p.right = new TreeNode(3);

  // Tree 2:   1
  //          / \
  //         2   3
  TreeNode q = new TreeNode(1);
  q.left = new TreeNode(2);
  q.right = new TreeNode(3);

  SameTree obj = new SameTree();
  boolean result = obj.isSameTree(p, q);
  System.out.println("Are the trees the same? " + result); // Output should be true
  }
}
