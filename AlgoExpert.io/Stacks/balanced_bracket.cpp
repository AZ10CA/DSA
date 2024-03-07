#include <stack>
#include <iostream>

using namespace std;

bool isOpening(char ch) {
    return ch == '{' || ch == '(' || ch == '[';
}

bool isClosing(char ch) {
    return ch == '}' || ch == ')' || ch == ']';
}

bool isMatching(const stack<char> &st, char ch) {
    auto top = st.top();
    return (top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']');
}

bool balancedBrackets(string str) {
    stack<char> st;
    for (auto ch: str) {
        if (!isOpening(ch) && !isClosing(ch))
            continue;
        if (isOpening(ch)) {
            st.push(ch);
        } else {
            if (st.empty())
                return false;
            if (isMatching(st, ch)) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
