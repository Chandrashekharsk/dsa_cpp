
public class NumberOfProvinces {
  private static int[][]  dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  private void dfs(int r, int c, int[][] isConnected, int N){
    if(isConnected[r][c] == 0) return;
    isConnected[r][c] = 0;
    for(int[] d: dirs){
      int nr = r+d[0], nc = c+d[1];
      if(nr>=0 && nc>=0 && nr<N && nc<N) dfs(nr, nc, isConnected, N);
    }
  }
  
  public int findCircleNum(int[][] isConnected) {
    int N = isConnected.length;
    int provincesCnt = 0;

    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        if(isConnected[i][j]==1){
          dfs(i,j, isConnected, N);
          ++provincesCnt;
        }
      }
    }
    return provincesCnt;
  }

  public static void main(String[] args) {
    NumberOfProvinces np = new NumberOfProvinces();

    // ✅ Example 1
    int[][] isConnected1 = {
      {1,1,0},
      {1,1,0},
      {0,0,1}
    };
    System.out.println(np.findCircleNum(isConnected1)); // Output: 2

    // ✅ Example 2
    int[][] isConnected2 = {
      {1,0,0},
      {0,1,0},
      {0,0,1}
    };
    System.out.println(np.findCircleNum(isConnected2)); // Output: 3
  }
}
