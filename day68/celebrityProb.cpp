#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int findCeleb(vector<vector<int>>& nums){
  stack<int> st;
  for(int i=0; i<nums.size(); ++i){
    st.push(i);
    while(st.size()>1){
      int i = st.top(); st.pop();
      int j = st.top(); st.pop();
      if(nums[i][j] == 0){
        st.push(i);
      }else{
        st.push(j);
      }
    }
  }
  int possibleCeleb = st.top(); st.pop();
  for(int i=0; i<nums.size(); ++i){
    if(i!=possibleCeleb && nums[i][possibleCeleb] == 0 || nums[possibleCeleb][i] == 1){
      return -1;
    };
  };
  return possibleCeleb;
};

int main(){
  vector<vector<int>> nums = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
  cout<<findCeleb(nums);


  return 0;
}