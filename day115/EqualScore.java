public class EqualScore {
  public boolean scoreBalance(String s) {
    int totSum = 0;
    for (char c : s.toCharArray())
      totSum += (int) (c - 'a') + 1;
    int prevSum = 0;
    for (char c : s.toCharArray()) {
      prevSum += (int) (c - 'a') + 1;
      if (prevSum == totSum - prevSum)
        return true;
    }
    return false;
  }

  public static void main(String[] args) {
    
  }
}
