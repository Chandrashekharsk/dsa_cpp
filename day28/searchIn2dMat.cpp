// 74. Search a 2D Matrix
#include<iostream>
#include<vector>
using namespace std;

bool binarySearchInRow(vector<vector<int>> mat, int midR, int target){
  int st = 0, end =mat[midR].size()-1;

  while(st<=end){
    int midC = st + (end-st)/2;
    if(mat[midR][midC]== target) return true;
    else if(mat[midR][midC]<target) st = midC+1;
    else end = midC-1;
  }
  return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target){
  int st=0, end = matrix.size()-1;

  while(st<=end){
    int midR = st+(end-st)/2;
    if(matrix[midR][0]<= target && target <= matrix[midR][matrix[midR].size()-1]){
      return binarySearchInRow(matrix ,midR, target);
    }else if(target< matrix[midR][0]){
      end = midR-1;
    }else{
      st = midR+1;
    }
  }
  return false;
}

int main(){

  vector<vector<int>>matrix =  {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  cout<< searchMatrix(matrix, 8);

  return 0;
}