// 105. Construct Binary Tree from Preorder and Inorder Traversal
import java.util.HashMap;
import java.util.Map;

class TreeNode {
  int val;
  TreeNode left, right;
  public TreeNode(int n) { val = n; }
}

public class ConstrutBT {
  private int preorderIdx;
  private Map<Integer,Integer> inorderMap;

  private TreeNode helper(int[] preorder, int inSt, int inEnd) {
    if(inSt>inEnd) return null;
    int rootVal = preorder[preorderIdx++];
    TreeNode root = new TreeNode(rootVal);

    int inorderRootIdx = inorderMap.get(rootVal);
    root.left = helper(preorder, inSt, inorderRootIdx-1);
    root.right = helper(preorder, inorderRootIdx+1, inEnd);
    return root;
  }

  public TreeNode buildTree(int[] preorder, int[] inorder) {
    preorderIdx = 0;
    inorderMap = new HashMap<>();
    for(int i = 0; i<inorder.length; ++i) inorderMap.put(inorder[i], i);

    return helper(preorder, 0, inorder.length-1);
  }

  private void printPreorder(TreeNode root) {
    if (root == null)
      return;
    System.out.print(root.val + " ");
    printPreorder(root.left);
    printPreorder(root.right);
  }


  public static void main(String[] args) {
    int[] preorder = { 3, 9 };
    int[] inorder = { 3, 9 };
    // int[] preorder = { 3, 9, 20, 15, 7 };
    // int[] inorder = { 9, 3, 15, 20, 7 };

    ConstrutBT tree = new ConstrutBT();
    TreeNode root = tree.buildTree(preorder, inorder);

    System.out.println("Preorder Traversal of Constructed Tree:");
    tree.printPreorder(root); // Expected: 3 9 20 15 7
  }
}
