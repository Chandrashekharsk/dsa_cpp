// 547. Number of Provinces 

public class NumberOfProvinces {
  private void dfs(int city, int[][] isConnected,boolean[] vis, int N){
    vis[city] = true;

    for(int neighbourCity=0; neighbourCity<N; ++neighbourCity){
      if(isConnected[city][neighbourCity]==1 && !vis[neighbourCity]) dfs(neighbourCity, isConnected, vis, N);
    }
  }
  
  public int findCircleNum(int[][] isConnected) {
    int N = isConnected.length;
    int provincesCnt = 0;
    boolean[]  vis = new boolean[N];

    for(int i=0; i<N; ++i){
      if(!vis[i]){
        dfs(i, isConnected, vis, N);
        ++provincesCnt;
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
