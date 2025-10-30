// 455. Assign Cookies
import java.util.Arrays;

public class AssignCookies {
  public int findContentChildren(int[] g, int[] s) {
    Arrays.sort(g);
    Arrays.sort(s);
    int i = 0, j = 0;
    while (i < g.length && j < s.length) {
      if (s[j] >= g[i]) ++i;
      ++j;
    }
    return i;
  }


  public static void main(String[] args) {
    AssignCookies as = new AssignCookies();
    System.out.println(as.findContentChildren(new int[] { 1, 2 }, new int[] { 1, 2, 3 }));
  }
}