import java.util.ArrayList;

public class ArrayListIntro {
  public static void main(String[] args) { // Fixed method name and parameter type

    ArrayList<Integer> list = new ArrayList<>(); // No need to repeat Integer in diamond operator

    list.add(1);
    list.add(2);
    list.add(3);

    System.out.println(list); // Correct usage

    for (int i : list) { // Corrected loop syntax
      System.out.println(i); // Fixed syntax for printing
    }
  }
}
