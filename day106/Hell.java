// 449. Serialize and Deserialize BST
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class  TreeNode {
  int val;
  TreeNode left, right;
  public TreeNode(int n){
    val = n;
  }
}

public class Hell {
  private void helper (TreeNode root, StringBuilder sb){
    if(root == null){
      sb.append("null,");
      return;
    }
    sb.append(root.val).append(',');
    helper(root.left, sb);
    helper(root.right, sb);
  }
  
  public String serialize(TreeNode root) {
    StringBuilder sb = new StringBuilder();
    helper(root, sb);
    return sb.toString();
  }

  private TreeNode helper2(Queue<String> nodes){
    if(nodes.size()==0) return null;
    String front = nodes.poll();
    if(front.equals("null")) return null;

    TreeNode root = new TreeNode(Integer.parseInt(front));
    root.left = helper2(nodes);
    root.right = helper2(nodes);
    return root;
  }
  public TreeNode deserialize(String data) {
    String[] strs = data.split(",");
    Queue<String> nodes = new LinkedList<>(Arrays.asList(strs));
    return helper2(nodes);
  }

  private void printPreOrder(TreeNode root){
    if(root == null) return;
    System.out.print(root.val+" ");
    printPreOrder(root.left);
    printPreOrder(root.right);
  }

  public static void main(String[] args) {
    Hell cd = new Hell();
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.left.left = new TreeNode(4);
    root.right = new TreeNode(3);
    System.out.println(cd.serialize(root));
    cd.printPreOrder(cd.deserialize(cd.serialize(root)));
  }
}