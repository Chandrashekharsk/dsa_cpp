// 994. Rotting Oranges
import java.util.LinkedList;
import java.util.Queue;

public class RottenOranges {
  public int orangesRotting(int[][] grid) {
    if(grid==null || grid.length == 0) return -1;
    Queue<int[]> q = new LinkedList<>();
    int rows = grid.length, cols = grid[0].length, fresh = 0;

    for(int i=0; i<rows; ++i){
      for(int j=0; j<cols; ++j){
        if(grid[i][j] == 2) q.offer(new int[]{i, j});
        if(grid[i][j] == 1) ++fresh;
      }
    }

    if(fresh == 0) return 0;
    int minutes = -1;
    int[][] directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while (!q.isEmpty()) {
      ++minutes;
      int size = q.size();
      for(int i=0; i<size; ++i){
        int[] RottenOrange = q.poll();
        int r = RottenOrange[0], c = RottenOrange[1];

        for(int[] dir : directions){
          int nr = r + dir[0], nc = c + dir[1];
          if(nr>=0 && nc>=0 && nr<rows && nc< cols && grid[nr][nc]==1){
            grid[nr][nc] = 2;
            q.offer(new int[]{nr, nc});
            --fresh;
          }
        }
      }
    }

    return fresh == 0 ?  minutes : -1;
  }

  public static void main(String[] args) {
    RottenOranges solver = new RottenOranges();

    // Sample input
    int[][] grid = {
      {2, 1, 1},
      {1, 1, 0},
      {0, 1, 1}
    };

    int result = solver.orangesRotting(grid);
    System.out.println("Minutes until all oranges rot = " + result);
  }
}
