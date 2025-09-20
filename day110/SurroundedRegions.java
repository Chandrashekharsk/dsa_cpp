// 130. Surrounded Regions

public class SurroundedRegions {
  private static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  private void dfs(int r, int c, int m, int n, char[][] board){
    if(r<0 || c<0 || r>=m || c>=n || board[r][c]!='O') return;

    board[r][c] = '#';
    for(int[] dir: dirs) dfs(r+dir[0], c+dir[1], m, n, board);
  }
  public void solve(char[][] board) {
    int m = board.length, n = board[0].length;

    for(int c=0; c<n; ++c){
      if(board[0][c] == 'O') dfs(0, c, m, n, board);
      if(board[m-1][c] == 'O') dfs(m-1, c, m, n, board);
    }
    for(int r=0; r<m; ++r){
      if(board[r][0] == 'O') dfs(r, 0, m, n, board);
      if(board[r][n-1] == 'O') dfs(r, n-1, m, n, board);
    }

    for(int i=0; i<m; ++i){
      for(int j=0; j<n; ++j){
        if(board[i][j]=='O') board[i][j] = 'X';
        else if(board[i][j]=='#') board[i][j] = 'O';
      }
    }
  }

  public static void main(String[] args) {
    SurroundedRegions sr = new SurroundedRegions();

    char[][] board = {
      {'X','X','X','X'},
      {'X','O','O','X'},
      {'X','X','O','X'},
      {'X','O','X','X'}
    };

    System.out.println("Before solving:");
    printBoard(board);

    sr.solve(board);

    System.out.println("\nAfter solving:");
    printBoard(board);
  }

  private static void printBoard(char[][] board){
    for(char[] row : board){
      for(char c : row){
        System.out.print(c + " ");
      }
      System.out.println();
    }
  }
}
