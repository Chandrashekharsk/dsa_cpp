// 68. Text Justification
import java.util.ArrayList;
import java.util.List;

public class TextJustification {
  public static List<String> fullJustify(String[] words, int maxWidth) {
    List<String> ans = new ArrayList<>();
    int index = 0;

    while (index < words.length) {
      int totalChars = words[index].length();
      int last = index + 1;

      while (last < words.length) {
        if (totalChars + 1 + words[last].length() > maxWidth)  break;
        totalChars += 1 + words[last].length();
        last++;
      }

      StringBuilder sb = new StringBuilder();
      int numWords = last - index;
      int numSpaces = maxWidth - totalChars + (numWords - 1);

      if (last == words.length || numWords == 1) {
        for (int i = index; i < last; i++) {
          sb.append(words[i]);
          if (i < last - 1) sb.append(" ");
        }
        while (sb.length() < maxWidth) sb.append(" ");
      } else {
        int space = numSpaces / (numWords - 1);
        int extra = numSpaces % (numWords - 1);

        for (int i = index; i < last; i++) {
          sb.append(words[i]);
          if (i < last - 1) {
            for (int s = 0; s < space + (i - index < extra ? 1 : 0); s++)
              sb.append(" ");
          }
        }
      }
      ans.add(sb.toString());
      index = last;
    }

    return ans;
  }

  public static void main(String[] args) {
    String[] strs = { "This", "is", "an", "example", "of", "text", "justification." };
    for (String s : fullJustify(strs, 16))
      System.out.println("'" + s + "'");
  }
}
