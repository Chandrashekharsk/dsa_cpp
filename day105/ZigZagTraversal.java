// 103. Binary Tree Zigzag Level Order Traversal
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Deque;

class TreeNode {
  int val;
  TreeNode left, right;
  public TreeNode(int n) {
    val = n;
  }
}

public class ZigZagTraversal {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    if (root == null) return ans;
    
    boolean reverse = false;
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    while (!q.isEmpty()) {
      int size = q.size();
      Deque<Integer> lvl = new LinkedList<>();

      for (int i = 0; i < size; ++i) {
        TreeNode currNode = q.poll();
        if(reverse) lvl.addFirst(currNode.val);
        else lvl.add(currNode.val);

        if (currNode.left != null) q.add(currNode.left);
        if (currNode.right != null) q.add(currNode.right);
      }

      ans.add(new ArrayList<>(lvl));
      reverse = !reverse;
    }
    return ans;
  }

  public static void main(String[] args) {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.left = new TreeNode(6);
    root.right.right = new TreeNode(7);

    ZigZagTraversal zz = new ZigZagTraversal();
    List<List<Integer>> result = zz.zigzagLevelOrder(root);

    // Print result in the required format
    for (List<Integer> level : result) {
      System.out.print("[");
      for (int val : level) {
        System.out.print(val+" ");
      }
      System.out.println("]");
    }
  }
}