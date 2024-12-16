// Permutations of n => n!
#include<iostream>
#include<vector>
using namespace std;

void helper(int idx, string& s, vector<string>& ans){
  if(idx == s.size()){
    ans.push_back({s});
    return;
  }

  for(int i=idx; i<s.size(); i++){
    swap(s[idx], s[i]);
    helper(idx+1, s, ans);
    swap(s[idx], s[i]);
  }
}

vector<string> stringPermute(string s){
  vector<string> ans;
  helper(0, s, ans);
  return ans;
}

int main(){
  string s = "abc";
  for(auto i: stringPermute(s)){
    for(auto j: i){
      cout<< j;
    }
    cout<<endl;
  }


  return 0;
}