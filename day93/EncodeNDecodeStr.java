// 271. Encode and Decode Strings
import java.util.ArrayList;
import java.util.List;

public class EncodeNDecodeStr {

  // Encode a list of strings to a single string
  public String encode(List<String> strs){
    if(strs.size()==0) return "";
    StringBuilder sb = new StringBuilder();
    for(String s: strs){
      sb.append(s.length()).append('#').append(s);
    }
    return sb.toString();
  }

  // Decode the encoded string back to list of strings
  public List<String> decode(String s){
    List<String> ans = new ArrayList<>();
    if(s.length()==0) return ans;
    int idx = 0; 
    while(idx<s.length()){
      int j = idx;
      while(s.charAt(j) != '#') ++j;
      int strLen = Integer.parseInt(s.substring(idx, j));
      ++j;
      ans.add(s.substring(j, j+strLen));
      idx = j+strLen;
    }
    return ans;
  }

  // Main method to test encode/decode
  public static void main(String[] args) {
    EncodeNDecodeStr codec = new EncodeNDecodeStr();

    List<String> input = new ArrayList<>();
    input.add("apple");
    input.add("banana");
    input.add("");
    input.add("grape#fruit"); // edge case with special char

    String encoded = codec.encode(input);
    System.out.println("Encoded: " + encoded);

    List<String> decoded = codec.decode(encoded);
    System.out.println("Decoded:");
    for (String s : decoded) {
      System.out.println("'" + s + "'");
    }
  }
}
