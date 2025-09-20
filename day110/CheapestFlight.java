// 787. Cheapest Flights Within K Stops
import java.util.Arrays;

// USING BELLMAN FORD ALGO (cheapest cost from source -> destination)
public class CheapestFlight {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    int[] costs = new int[n];
    Arrays.fill(costs, Integer.MAX_VALUE);
    costs[src] = 0;
    
    for(int i=0; i<=k;++i){ // runs k+1 times
      int[] temp = costs.clone();

      for(int[] flight: flights){
        int from = flight[0], to = flight[1], currCost = flight[2];
        if(costs[from] == Integer.MAX_VALUE) continue;
        if(temp[to]>costs[from]+currCost) temp[to] = costs[from] + currCost;
      }
      costs = temp;
    }
    return costs[dst] == Integer.MAX_VALUE? -1: costs[dst];
  }


  public static void main(String[] args) {
    CheapestFlight solver = new CheapestFlight();

    int n = 4;
    int[][] flights = {
      {0, 1, 100},
      {1, 2, 100},
      {2, 3, 100},
      {0, 3, 500}
    };
    int src = 0, dst = 3, k = 1;
    int result = solver.findCheapestPrice(n, flights, src, dst, k);
    System.out.println("Cheapest price: " + result);
  }
}
