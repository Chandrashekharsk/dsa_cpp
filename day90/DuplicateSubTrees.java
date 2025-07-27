// 652. Find Duplicate Subtrees
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DuplicateSubTrees {
  static class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {};
    TreeNode(int val){
      this.val = val;
    } 
    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  private String helper(TreeNode root, Map<String, Integer> m, List<TreeNode> ans){
    if(root == null) return "";
    String key  = "(" + helper(root.left, m, ans) + ")"+ 
    root.val
    + "(" + helper(root.right, m, ans) + ")";
    
    m.put(key, m.getOrDefault(key, 0)+1);
    if(m.get(key)==2) ans.add(root);
    return key;
  }

  public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
    Map<String, Integer> m = new HashMap<>();
    List<TreeNode> ans = new ArrayList<>();

    helper(root, m, ans);
    return ans;
  }

  public void printDuplicateRoots(List<TreeNode> nodes) {
    for (TreeNode node : nodes) {
      System.out.print(node.val + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    TreeNode root = new TreeNode();
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);

    root.left.left = new TreeNode(4);

    root.right.left = new TreeNode(2);
    root.right.right = new TreeNode(4);

    root.right.left.left = new TreeNode(4);

    DuplicateSubTrees obj = new DuplicateSubTrees();
    List<TreeNode> result = obj.findDuplicateSubtrees(root);
    System.out.print("Duplicate Subtree Roots: ");
    obj.printDuplicateRoots(result);  // Expected output: 4 2
  }
}
