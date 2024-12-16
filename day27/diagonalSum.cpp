#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(int mat[][3], int n){
  int ans = 0;
  for(int i=0; i<n; i++){
    ans+= mat[i][i];

    if(i!= n-1-i){  //R1->(0,2) , R3->(2,0)
      ans+= mat[i][n-1-i];
    }
  }
  return ans;
}

int main(){

  int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  cout<< diagonalSum(matrix, 3);


  return 0;
}