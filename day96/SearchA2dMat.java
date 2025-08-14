// 74. Search a 2D Matrix

public class SearchA2dMat {
  public static boolean searchMatrix(int[][] matrix, int target) {
    // approach 1
    // int rowsLength = matrix.length;
    // int colsLength = matrix[0].length;

    // int top = 0, bottom = rowsLength;
    // int row = -1;
    // while(top<bottom){
    //   int mid = (bottom-top)/2 + top;
    //   if(matrix[mid][0]<=target && target<=matrix[mid][colsLength-1]){
    //     row = mid;
    //     break;
    //   }else if(matrix[mid][0]>target) bottom = mid-1;
    //   else top = mid+1;
    // }

    // if(row == -1) return false;

    // int st = 0, end = colsLength-1;
    // while(st<=end){
    //   int mid = (end-st)/2 + st;
    //   if(matrix[row][mid]==target) return true;
    //   else if(matrix[row][mid]>target) end = mid-1;
    //   else st = mid+1;
    // }

    // return false;

    
    // approach 2
    int cols = matrix[0].length, rows = matrix.length;
    int st = 0, end = cols*rows-1;

    while(st<=end){
      int mid = (end-st)/2 + st;
      int row = mid/cols, col = mid%cols;
      if(matrix[row][col]== target) return true;
      else if(matrix[row][col]<target){
        st = mid+1;
      }else end = mid-1;
    }
    return false;
  }
  public static void main(String[] args) {
    // int[][] nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int[][] nums = {{1},{3}};
    System.out.println(searchMatrix(nums, 2));
  }
}
