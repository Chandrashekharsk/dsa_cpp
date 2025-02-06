#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int>& prices){
  vector<int> ans;
  stack<int> st;

  int span = 0;
  for(int i=0; i<prices.size(); ++i){
    while(!st.empty() && prices[st.top()]<=prices[i]){
      st.pop();
    }
    if(st.empty()){
      span = i+1;
    }else{
      span = i - st.top();
    }
    ans.push_back(span);
    st.push(i);
  }
  return ans;
}

int main() {
  vector<int> prices = {NULL, 100, 80, 60, 70, 60, 75, 85};
  vector<int> ans = stockSpan(prices);
  for(int val : ans) cout << val << " ";
  cout << endl;

  return 0;
}