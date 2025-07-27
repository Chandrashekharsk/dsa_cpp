// 359. Logger Rate Limiter

import java.util.HashMap;
import java.util.Map;

public class LoggerMessage {
  public static class Logger {
    Map<String, Integer> m;
    int SPAM = 10;

    public Logger() {
      m = new HashMap<>();
    }

    public boolean shouldPrintMsg(int interval, String msg) {
      if (!m.containsKey(msg) || m.containsKey(msg) && (interval - m.get(msg)) >= SPAM){
        m.put(msg, interval);
        return true;
      }
      return false;
    }
  }

  public static void main(String[] args) {
    Logger logger = new Logger();
    // Sample test cases
    System.out.println(logger.shouldPrintMsg(1, "foo")); // true
    System.out.println(logger.shouldPrintMsg(2, "bar")); // true
    System.out.println(logger.shouldPrintMsg(3, "foo")); // false
    System.out.println(logger.shouldPrintMsg(11, "foo")); // true
    System.out.println(logger.shouldPrintMsg(12, "bar")); // true
  }
}
