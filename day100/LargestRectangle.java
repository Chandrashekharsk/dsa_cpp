// 84. Largest Rectangle in Histogram
import java.util.Stack;

public class LargestRectangle {
  public static int largestRectangleArea(int[] heights) {
    int maxArea = 0, n = heights.length;
    Stack<Integer> stk = new Stack<>();

    for (int i = 0; i <= n; ++i) {
      int currHeight = (i == n) ? 0 : heights[i];
      while (!stk.empty() && currHeight < heights[stk.peek()]) {
        int height = heights[stk.pop()];
        int width = (stk.empty())? i : i-stk.peek()-1;
        maxArea = Integer.max(maxArea, height * width);
      }
      stk.add(i);
    }
    return maxArea;
  }

  public static void main(String[] args) {
    System.out.println(largestRectangleArea(new int[] { 2, 4 }));
    System.out.println(largestRectangleArea(new int[] { 2, 1, 5, 6, 2, 3 }));
  }
}
