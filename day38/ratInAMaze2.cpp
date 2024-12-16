#include<iostream>
#include<vector>
using namespace std;

void helper(int r, int c, vector<vector<int>>& maze, string path,vector<string>& ans){
  if(r == maze.size()-1 && c==maze[0].size()-1){
    ans.push_back(path);
    return;
  }
  if(r<0 || r>=maze.size() || c<0 || c>= maze[0].size() || maze[r][c]==0 || maze[r][c]==-1) return;

  maze[r][c] = -1; // visit

  helper(r-1, c,maze,path+'U', ans);
  helper(r+1, c, maze, path+'D', ans);
  helper(r, c-1, maze, path+'L', ans);
  helper(r, c+1, maze, path+'R', ans);

  maze[r][c] = 1;  // Backtrack || unvisited
}

vector<string> ratInAMaze(vector<vector<int>>& maze){
  vector<string> ans;
  if(maze[0][0] == 0 || maze[maze.size()-1][maze[0].size()-1] == 0) return ans;
  helper(0, 0, maze,"", ans);
  return ans;
}

int main(){

  vector<vector<int>> maze ={
    {1, 0, 0, 0},
    {1, 1, 0, 1}, 
    {1, 1, 0, 0}, 
    {0, 1, 1, 1}
  };
  for(auto i: ratInAMaze(maze)){
    cout<< i<<"\n";
  }
  cout<<"\n";


  return 0;
}