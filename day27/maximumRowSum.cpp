#include<iostream>
#include<vector>
using namespace std;

int maxRowSum(int mat[][3], int rows, int cols){
  int ans=INT_MIN;
  int sum;

  for(int i=0; i<rows; i++){
    sum=0;
    for(int j=0; j<cols; j++){
      sum+= mat[i][j];
    }
    ans = max(ans, sum);
  }
  return ans;
}

int main(){

  int mat[][3] = {{1,2,3},{4,5,6},{7,8,9}};
  cout<<maxRowSum(mat, 3, 3);


  return 0;
}