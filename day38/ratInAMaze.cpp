#include <iostream>
#include <vector>
using namespace std;

void helper(int r, int c, vector<vector<int>>& maze, vector<string>& ans, string path) {
  if (r == maze.size() - 1 && c == maze[0].size() - 1) {
    ans.push_back(path);
    return;
  }
  // out of bounds or blocked
  if (c >= maze[0].size() || c < 0 || r >= maze.size() || r < 0 ||
      maze[r][c] == 0)
    return;

  maze[r][c] = 0;
  // down up left right
  helper(r + 1, c, maze, ans, path + "D");
  helper(r - 1, c, maze, ans, path + "U");
  helper(r, c - 1, maze, ans, path + "L");
  helper(r, c + 1, maze, ans, path + "R");
  maze[r][c] = 1;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
  vector<string> ans;
  helper(0, 0, maze, ans,"");
  return ans;
}

vector<string> helper2(int r, int c, vector<vector<int>>& maze, vector<vector<vector<string>>>& dp) {
  if (r == maze.size() - 1 && c == maze[0].size() - 1) return {""};
  if (c >= maze[0].size() || c < 0 || r >= maze.size() || r < 0 ||
      maze[r][c] == 0)
    return {};
  if (!dp[r][c].empty()) return dp[r][c];

  vector<string> paths;
  // Mark the cell as visited to avoid the loop
  maze[r][c] = 0;

  vector<string> down = helper2(r + 1, c, maze, dp);
  for (auto p : down) paths.push_back("D" + p);

  vector<string> up = helper2(r - 1, c, maze, dp);
  for (auto p : up) paths.push_back("U" + p);

  vector<string> left = helper2(r, c - 1, maze, dp);
  for (auto p : left) paths.push_back("L" + p);

  vector<string> right = helper2(r, c + 1, maze, dp);
  for (auto p : right) paths.push_back("R" + p);

  // Unmark the cell after exploring all directions
  maze[r][c] = 1;
  return dp[r][c] = paths;
}
vector<string> ratInMaze2(vector<vector<int>>& maze) {
  vector<vector<vector<string>>> dp(maze.size(), vector<vector<string>>(maze[0].size()));
  return helper2(0, 0, maze, dp);
}

int main() {
  vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  vector<string> paths = ratInMaze(maze);
  for (const auto& path : paths) cout << path << endl;
  cout<<"-----------------------\n";
  paths = ratInMaze2(maze);
  for (const auto& path : paths) cout << path << endl;

  return 0;
}
