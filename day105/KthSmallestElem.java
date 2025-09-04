// 230. Kth Smallest Element in a BST
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class KthSmallestElem {
  private List<Integer> sorted;
  private int result;
  
  private void inorder(TreeNode root, int k){
    if(root == null || result != -1) return;
    inorder(root.left, k);
    sorted.add(root.val);
    if(sorted.size() == k){
      result = root.val;
      return;
    }
    inorder(root.right, k);
  }

  public int kthSmallest(TreeNode root, int k) {
    sorted = new ArrayList<>();
    result = -1;

    inorder(root, k);
    return result;
  }

  public static void main(String[] args) {
    TreeNode root = new TreeNode(3);
    root.left = new TreeNode(1);
    root.left.right = new TreeNode(2);
    root.right = new TreeNode(4);

    KthSmallestElem solver = new KthSmallestElem();

    System.out.println("k=1 → " + solver.kthSmallest(root, 1)); // Expected 1
    System.out.println("k=2 → " + solver.kthSmallest(root, 2)); // Expected 2
    System.out.println("k=3 → " + solver.kthSmallest(root, 3)); // Expected 3
    System.out.println("k=4 → " + solver.kthSmallest(root, 4)); // Expected 4
  }
}