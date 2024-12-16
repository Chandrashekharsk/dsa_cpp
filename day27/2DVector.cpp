#include<iostream>
#include<vector>
using namespace std;

pair<int, int> findKey(vector<vector<int>> mat, int key){
for(int i=0; i<mat.size(); i++){
  for(int j=0; j<mat[i].size(); j++){
      if(mat[i][j]== key) return {i,j};
    }
  }
  return {-1,-1};
}

int colsSum(vector<vector<int>> mat){
  int ans = 0;
  for(int i=0; i<mat.size(); i++){
    int sum = 0;
    for(int j=0; j<mat[i].size(); j++){
      sum += mat[i][j];
    }
    ans = max(ans,sum);
  }
  return ans;
}


int main(){

// vector<vector<int>> mat = {{1,2,3},{4,5,6,20,40},{7,8,9}};
// // cout<< mat.size()<<"\n";
// for(int i=0; i<mat.size(); i++){
//   for(int j=0; j<mat[i].size(); j++){
//     cout<<mat[i][j]<<" ";
//   }
//   cout<<"\n";
// }

vector<vector<int>> mat = {{1,2,3},{4,5,6,20,40},{7,8,9}};
int key=9;
pair<int,int> p = findKey(mat, key);
cout<< p.first<<", "<<p.second;

cout<<"\n"<<colsSum(mat);

  return 0;
}