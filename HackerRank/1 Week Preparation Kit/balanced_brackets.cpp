#include <iostream>
#include <stack>

using namespace std;

bool is_opening(char ch){
    return ch == '(' || ch == '[' || ch == '{';
}

bool is_matching(char first, char second){
    return (first == '{' && second == '}') || (first == '[' && second == ']') || (first == '(' && second == ')');
}

bool is_bracket(char ch){
    return ch == '}' or ch == ')' or ch == ']' or is_opening(ch);
}

string solution(const string& str){
    stack<char> st;
    for(auto ch: str){
        if(is_bracket(ch)){
            if(is_opening(ch))
                st.push(ch);
            else if(st.size() && is_matching(st.top(), ch)){
                st.pop();
            } else {
                return "NO";
            }
        }
    }
    
    return st.empty() ? "YES" : "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        cout << solution(input) << endl;
    }
    return 0;
}
