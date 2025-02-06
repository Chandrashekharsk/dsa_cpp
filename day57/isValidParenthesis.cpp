// 20. Valid Parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid2(const string& s){
    if(s.length() % 2 != 0) return false;
    stack<char> st;

    for(char c:s){
      if(c == '(' || c == '[' || c == '{'){
        st.push(c);
      }else{
        if(st.empty()) return false;
        if((c == ')' && st.top() == '(' ) || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')){
          st.pop();
        }else{
          return false;
        }
      }
    }
    return st.empty();
  }
};

int main() {
  Solution s;
  // string str = "()";
  // string str = "{()]";
  // string str = "]]]";
  string str = "((";
  cout << s.isValid2(str) << endl;
  

  return 0;
}