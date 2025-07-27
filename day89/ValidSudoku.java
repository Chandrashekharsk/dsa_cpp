// 36. Valid Sudoku
import java.util.HashSet;
import java.util.Set;

public class ValidSudoku {
  
  public boolean isValidSudoku(char[][] board) {
    // check horizontally
    for(int i=0; i<9; ++i){
      Set<Character> rs = new HashSet<>();
      Set<Character> cs = new HashSet<>();
      Set<Character> bs = new HashSet<>();

      for(int j=0; j<9; ++j){
        // horizontally
        if(board[i][j] != '.'){
          if(!rs.add(board[i][j])) return false;
        }
        // vertically
        if(board[j][i] != '.'){
          if(!cs.add(board[j][i])) return false;
        }


        // grid 
        int rowIdx = 3* (i/3);
        int colIdx = 3* (i%3);
        int r = rowIdx + j/3;
        int c = colIdx + j%3;
        if(board[r][c] != '.'){
          if(!bs.add(board[r][c])) return false;
        }
      }
    }
    return true;
  }

  public static void main(String[] args) {
    char[][] board = {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}
    };
    ValidSudoku vs = new ValidSudoku();
    boolean result = vs.isValidSudoku(board);
    System.out.println("Is valid sudoku? " + result);
  }
}
