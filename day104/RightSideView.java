// 199. Binary Tree Right SideView
import java.util.ArrayList;
import java.util.List;

class TreeNode{
  int val;
  TreeNode left;
  TreeNode right;
  public TreeNode(int n){
    val = n;
  }
}
public class RightSideView {
  private void helper(TreeNode root, int ht, List<Integer> ans){
    if(root == null) return;
    if(ans.size()==ht) ans.add(root.val);
    helper(root.right, ht+1, ans);
    helper(root.left, ht+1, ans);
  }
  public List<Integer> rightSideView(TreeNode root){
    List<Integer> ans = new ArrayList<>();
    if(root == null) return ans;
    helper(root, 0, ans);
    return ans;
  }
  public static void main(String[] args) {
  // Sample input: Constructing a binary tree
  //      1
  //     / \
  //    2   3
  //     \   \
  //      5   4
  TreeNode root = new TreeNode(1);
  root.left = new TreeNode(2);
  root.right = new TreeNode(3);
  root.left.right = new TreeNode(5);
  root.right.right = new TreeNode(4);

  RightSideView obj = new RightSideView();
  List<Integer> view = obj.rightSideView(root);
  System.out.println("Right side view: " + view); // Output should be [1, 3, 4]
  }
}
