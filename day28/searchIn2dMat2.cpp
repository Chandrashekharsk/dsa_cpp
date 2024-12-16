// 240. Search a 2D Matrix II
#include<iostream>
#include<vector>
using namespace std;

bool searchInMatrix(vector<vector<int>>& mat, int target){
  int row = 0, col = mat[0].size()-1;
  while(col >= 0 && row <= mat.size()-1){
    if(target == mat[row][col]) return true;
    else if (target< mat[row][col]) col--;
    else row++;
  }
  return false;
}

int main(){

vector<vector<int>>mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  // cout<< searchInMatrix(mat, 5);
  cout<< searchInMatrix(mat, 39);

  return 0;
}