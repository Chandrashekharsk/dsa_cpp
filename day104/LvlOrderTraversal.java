// 102. Binary Tree Level Order Traversal
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}

public class LvlOrderTraversal{
  public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    if(root == null) return ans;
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);

    while (!q.isEmpty()) {
      int lvlSize = q.size();
      List<Integer> lvl = new ArrayList<>();
      for(int i=0; i<lvlSize; ++i){
        TreeNode currNode = q.poll();
        lvl.add(currNode.val);

        if(currNode.left != null) q.add(currNode.left);
        if(currNode.right != null) q.add(currNode.right);
      }
      ans.add(lvl);
    }
    return ans;
  }

  public static void main(String[] args) {
  // Sample input: Constructing a binary tree
  //      1
  //     / \
  //    2   3
  //   / \
  //  4   5
  TreeNode root = new TreeNode(1);
  root.left = new TreeNode(2);
  root.right = new TreeNode(3);
  root.left.left = new TreeNode(4);
  root.left.right = new TreeNode(5);

  LvlOrderTraversal obj = new LvlOrderTraversal();
  List<List<Integer>> levels = obj.levelOrder(root);
  System.out.println("Level order traversal: " + levels); // Output should be [[1], [2, 3], [4, 5]]
  }
}