// 151. Reverse Words of Sentence
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// optimize code 
string reverseWords1(string s) {
        string ans;
        bool isFirstWord = true;

        for(int i=s.length()-1; i>=0; i--){
            while(i>=0 && s[i] == ' ') i--;

            int j=i;
            while(j>=0 && s[j] != ' ') j--;

            if(i>=0){
                if(!isFirstWord) ans+= " ";
                ans += s.substr(j+1,i-j); // start, size
                isFirstWord = false;
            }
            i = j;
        }
    }
string reverseWords(string s){
    reverse(s.begin(), s.end());
    string ans = "";
    bool isFirstWord = true;  // Moved outside the loop

    for(int i=0; i<s.length(); i++){
        string word = "";
        while(i < s.length() && s[i] != ' '){
            word = s[i] + word;
            i++;
        }
        if(!word.empty()){
            if(!isFirstWord) ans += " ";  // Adds a space only after the first word
            ans += word;
            isFirstWord = false;  // Set to false after the first word
        }
    }
    return ans;
}

int main(){
    string s = " the    pen ";
    string res = reverseWords1(s);
    cout << "Result: \"" << res << "\"\n";
    cout << "Length of result: " << res.length() << "\n";

    return 0;
}
