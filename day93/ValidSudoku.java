// 36. Valid Sudoku

import java.util.HashSet;
import java.util.Set;

public class ValidSudoku {
  public static boolean isVAlidSudoku(char[][] board) {

    for (int i = 0; i < 9; ++i) {
      Set<Character> rowSet = new HashSet<>();
      Set<Character> colSet = new HashSet<>();
      Set<Character> boxSet = new HashSet<>();

      for (int j = 0; j < 9; ++j) {
        // check row wise
        if (board[i][j] != '.' && !rowSet.add(board[i][j]))
          return false;

        // check col wise
        if (board[j][i] != '.' && !colSet.add(board[j][i]))
          return false;

        // check box wise
        int row = (i / 3) * 3;
        int col = (i % 3) * 3;
        int rowIdx = (j / 3) + row;
        int colIdx = (j % 3) + col;
        if (board[rowIdx][colIdx] != '.' && !boxSet.add(board[rowIdx][colIdx]))  return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    char[][] board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    System.out.println(isVAlidSudoku(board)); // Call the function here
  }
}
