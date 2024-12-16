#include<iostream>
#include<vector>
using namespace std;

// linear search in 2D matrix
pair<int,int> linearSearch(int mat[][3], int rows, int cols, int key){
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(mat[i][j]==key) return {i,j};
    }
  }
  return {-1,-1};
}


int main(){

  int matrix[4][3] = {{1,2,3}, {4,5,6}, {7,8,9},{10,11,12}};
  cout<<matrix[2][1] <<"\n";
  matrix[2][1] = 18;
  cout<<matrix[2][1] <<"\n";

  int rows=4, cols = 3;
  // for(int i=0; i<rows; i++){
  //   for(int j=0; j<cols; j++){
  //     cout<<matrix[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }



  int key=7;
  pair<int,int> p = linearSearch(matrix, rows, cols, key);
  cout<<p.first<<" "<<p.second;
  

  return 0;
}