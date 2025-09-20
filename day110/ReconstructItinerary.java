// 332. Reconstruct Itinerary

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class ReconstructItinerary {
  private void dfs(String airport, Map<String, PriorityQueue<String>> graph, List<String> ans){
    PriorityQueue<String> destinations = graph.get(airport);
    while(destinations != null && !destinations.isEmpty()){
      String nextAirport = destinations.poll();
      dfs(nextAirport, graph, ans);
    }
    ans.addFirst(airport);
  }

  public List<String> findItinerary(List<List<String>> tickets) {
    Map<String,PriorityQueue<String>> graph = new HashMap<>();
    for(List<String> ticket : tickets){
      String from = ticket.get(0), to = ticket.get(1);
      graph.computeIfAbsent(from, k-> new PriorityQueue<>()).add(to);
    }

    List<String> ans = new LinkedList<>();
    dfs("JFK", graph, ans);
    return ans;
  }

  public static void main(String[] args) {
    ReconstructItinerary ri = new ReconstructItinerary();

    List<List<String>> tickets = new ArrayList<>();
    tickets.add(List.of("MUC", "LHR"));
    tickets.add(List.of("JFK", "MUC"));
    tickets.add(List.of("SFO", "SJC"));
    tickets.add(List.of("LHR", "SFO"));

    List<String> result = ri.findItinerary(tickets);
    System.out.println("Itinerary: " + result);
  }
}
