// 366. Find Leaves Of Binary Tree

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

public class FindLeaves {

  private int helper(TreeNode root, List<List<Integer>> ans){
    if(root == null) return -1;
    int lh = helper(root.left, ans), rh = helper(root.right, ans);
    int currHeight = 1 + Math.max(lh, rh);

    if(currHeight>= ans.size()) ans.add(new ArrayList<>());
    ans.get(currHeight).add(root.val);
    return currHeight;
  }
  public List<List<Integer>> findAllLeaves(TreeNode root){
    List<List<Integer>> ans = new ArrayList<>();
    helper(root, ans);
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

    FindLeaves obj = new FindLeaves();
    List<List<Integer>> leaves = obj.findAllLeaves(root);
    System.out.println("Leaves at each stage: " + leaves);
  }
}