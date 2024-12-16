// 131. Palindrome Partitioning
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(string str){
  string temp = str;
  reverse(temp.begin(), temp.end());
  return str == temp;
} 

void helper(string s, vector<string>& partitions, vector<vector<string>>& ans){
  if(s.empty()){
    ans.push_back(partitions);
    return;
  };

  for(int i=0; i<s.size(); i++){
    string leftPart = s.substr(0,i+1); // substr(startIndex, size);
    if(isPalindrome(leftPart)){
      partitions.push_back(leftPart);
      helper(s.substr(i+1), partitions, ans);
      partitions.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans;
  vector<string> partitions;
  helper(s, partitions, ans);
  return ans;
}

int main(){
  string s = "aab";
  for(auto i: partition(s)){
    for (auto j: i){
      cout<< j<<" ";
    }
    cout<<endl;
  }

  return 0;
}