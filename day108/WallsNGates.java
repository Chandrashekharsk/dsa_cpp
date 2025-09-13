// 286.Walls & Gates 
import java.util.LinkedList;
import java.util.Queue;

public class WallsNGates {

  public void wallsAndGates(int[][] rooms){
    Queue<int[]> q = new LinkedList<>();
    int m = rooms.length, n = rooms[0].length;

    for(int i=0; i<m; ++i){
      for(int j=0; j<n; ++j){
        if(rooms[i][j] == 0){
          q.offer(new int[]{i, j});
        }
      }
    }

    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dist = 0;
    while (!q.isEmpty()) {
      int size = q.size();
      ++dist;


      for(int i=0; i<size; ++i ){
        int[] curr = q.poll();
        int r = curr[0], c = curr[1];
        for(int[] dir: directions){
          int nr = r+dir[0], nc = c+dir[1];
          if(nr>=0 && nc>=0 && nr<m && nc<n && rooms[nr][nc] != -1 && rooms[nr][nc] != 0 && dist<rooms[nr][nc]){
            rooms[nr][nc] = dist;
            q.offer(new int[]{nr, nc});
          }
        }
      }
    }

  }
  public static void main(String[] args) {
    WallsNGates solver = new WallsNGates();
    // INF representation
    int INF = Integer.MAX_VALUE;
    // -1 = wall
    // 0 = gate
    // INF (large number, e.g. 2^31 - 1) = empty room
    int[][] rooms = {
      {INF,  -1,   0,  INF},
      {INF, INF, INF,  -1},  
      {INF,  -1, INF,  -1}, 
      {0,    -1, INF, INF}  
    };

    System.out.println("Before:");
    printGrid(rooms);

    solver.wallsAndGates(rooms);

    System.out.println("\nAfter:");
    printGrid(rooms);
  }
  private static void printGrid(int[][] grid) {
    for (int[] row : grid) {
      for (int val : row) {
        if (val == Integer.MAX_VALUE) {
          System.out.print("INF ");
        } else {
          System.out.print(val + " ");
        }
      }
      System.out.println();
    }
  }
}
